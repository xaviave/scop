/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:32:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 23:06:53 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
Need function to use:	- new gdata->win -> OK 
						- clear gdata->win -> glClear
						- put pixel -> glDrawPixel but not optim maybe create a texture see link 1
						- new image
						- get data addr
						- put image to gdata->win
						- get color value
						- loop / loop_hook / expose_hook / key_hook / mous_hook
						- auto replay for hook
						- put string
						- xpm to image
						- destroy image
						- swap buffer -> flushGLContext
						- change context ->  selectGLContext
						
1 - http://www.multigesture.net/articles/how-to-draw-pixels-to-a-texture-opengl/
TO DO:
		- put pixel (char-RGB) in a texture of the size of a screen
		- draw lines
		- load img (xpm free to use else code it or change imaeg type to xpm)
		- create image (load image and put it in a texture)
		- multi screen in gdata->wins
		- change screen (context)
		MATRIX:
		- create a lib to computate matrix
		- mutliply
		- add
		- pow
		MENU: 
		- create rect | circle | fonts -> for menus
		- create hit box for button and other things
add things when we things about it
*/


// refaire la fonction d en dessous avec que des vertexes et des shaders customs
/*
void render()
{
	GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
        return ;
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( W, H, "Hello World", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return ;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, W, H ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, W, 0, H, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    
    GLfloat lineVertices[] =
    {
        200, 100, 0,
        100, 300, 0,
        500, 50, 0,
        320, 100, 0,
        10, 10, 0
    };

    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices );
        glDrawArrays( GL_LINE_LOOP, 0, 5 );
        glDisableClientState( GL_VERTEX_ARRAY );
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    glfwTerminate( );
}
*/


void		error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void		key_callback(GLFWwindow *win, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GLFW_TRUE);
}

// pas de librarie de:	- matrixes
// 						- 3d
//						- load shader
// ok vertex
void		terminate_reader(t_gdata *gdata)
{
	glfwDestroyWindow(gdata->win);
	// need to free gdata->obj | gdata->mtl
	glfwTerminate();
}

void			render(t_gdata *gdata)
{
	float		tab[6];
	float		*tmp_data;
	t_matrix	*m;
	t_matrix	*p;
	t_matrix	*mvp;
	t_matrix	*tmp;
	t_matrix	*rotate;

	m = init_identity_matrix4x4();
	p = new_matrix(4, 4);
	mvp = new_matrix(4, 4);
	tmp = new_matrix(4, 4);
	rotate = new_matrix(4, 4);
	gdata->engine->view = new_matrix(4, 4);
	gdata->engine->projection = new_matrix(4, 4);
	tab[0] = -(float)W / (float)H;
	tab[1] = (float)W / (float)H;
	tab[2] = -1.0f;  // coord
	tab[3] = 1.0f;  // coord 
	tab[4] = 1.0f;  // coord
	tab[5] = -1.0f;  // coord
	while (!glfwWindowShouldClose(gdata->win))
	{
		gdata->time = tan(glfwGetTime());
        glClear(GL_COLOR_BUFFER_BIT);
        identity_matrix4x4(m);
		rotate_matrix4x4_y(rotate, m, gdata->time);
		ortho_matrix4x4(p, tab);
		multiply_matrix4x4(mvp, p, rotate);

		// look_at_matrix4x4(gdata->engine->view, gdata->engine->camera, 1);
		// perspective_matrix4x4(gdata->engine->projection, degree_to_radians(45.0f),
		// 	(float)W / (float)H, 0.1f, 100.0f);

		// multiply_matrix4x4(tmp, gdata->engine->projection, gdata->engine->view);
		
		multiply_matrix4x4(mvp, p, rotate);

		tmp_data = transform_matrix4x4_to_float(mvp);
        glUseProgram(gdata->engine->program);
		// put matrix in program | not calculus or transformation
		
        glUniformMatrix4fv(gdata->engine->mvp_location, 1, GL_FALSE, (GLfloat*)tmp_data);
        glDrawArrays(GL_TRIANGLES, 0, 3);
		if (tmp_data)
			free(tmp_data);
        glfwSwapBuffers(gdata->win);
		glfwPollEvents();
	}
	terminate_reader(gdata);
}

int         launch_render(t_gdata *gdata, t_parser *parser)
{
    if (!init_gdata(gdata, parser))
		return (0);
	init_shader(gdata->engine);
	render(gdata);
	return (1);
}