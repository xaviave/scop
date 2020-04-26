/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 23:07:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/26 19:37:54 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define WORD 2
#define DWORD 4
#define LONG 4

typedef struct {
	unsigned int bfSize;
	unsigned int bfOffBits;
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned int biBitCount;
	unsigned int biSizeImage;
	unsigned char* content;
} BitmapImage;

int read_next_bytes(FILE *file, unsigned int bytes)
{
	int total = 0;

	for (unsigned int i = 0; i < bytes; i++) {
		total += (fgetc(file) << (8 * i));
	}
	return total;
}

bmp_parse_file(BitmapImage *pImage, FILE *file)
{
	int currentByte;
	long int cursor;

	while ((currentByte = fgetc(file)) != EOF) {
		cursor = ftell(file);
		if (cursor == 3)
			pImage->bfSize = currentByte + read_next_bytes(file, (DWORD - 1));

		else if (cursor == 11)
			pImage->bfOffBits = currentByte + read_next_bytes(file, (DWORD - 1));

		else if (cursor == 15)
			pImage->biSize = currentByte + read_next_bytes(file, (DWORD - 1));

		else if (cursor == 19)
			pImage->biWidth = currentByte + read_next_bytes(file, (LONG - 1));

		else if (cursor == 23)
			pImage->biHeight = currentByte + read_next_bytes(file, (LONG - 1));

		else if (cursor == 29)
			pImage->biBitCount = currentByte + read_next_bytes(file, (WORD - 1));

		else if (cursor == 35)
			pImage->biSizeImage = currentByte + read_next_bytes(file, (DWORD - 1));

		// content
		else if (cursor == (pImage->bfOffBits + 1)) {
			pImage->content = (unsigned char*)malloc(pImage->biSizeImage);
			pImage->content[0] = currentByte;
			for (unsigned int i = 1; i < pImage->biSizeImage; i++) {
				int byte = fgetc(file);
				pImage->content[i] = byte;
			}
		}
	}
}

void				create_texture(t_gdata *gdata, char *name)
{
	FILE *bitmapFile;
	BitmapImage			img;

	bitmapFile = fopen(name, "rb");
	bmp_parse_file(&img, bitmapFile);
	glGenTextures(1, &gdata->engine->texture_id);
	glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.biWidth,
		img.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img.content);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}
