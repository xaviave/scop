from os import listdir, system, path


MAKER = "make"
BINARY = "./scop"
DIFF_BINARY = "diff"
RM_BINARY = "rm -f"
TESTS_PATH = path.join("data", "tests")
DIFFS_PATH = path.join(TESTS_PATH, "diffs")
LOG_FILE = path.join(TESTS_PATH, "test_log")


def main():
    test_files = [f for f in sorted(listdir(TESTS_PATH)) if f != "test_log" and path.isfile(path.join(TESTS_PATH, f))]
    system(MAKER)
    for file in test_files:
        print(f"\n\n\n_________/ File: {file}\n")
        system(f"{BINARY} {path.join(TESTS_PATH, file)} > {LOG_FILE}")
        print(f"    Diff:\n")
        state = system(f"{DIFF_BINARY} {path.join(DIFFS_PATH, file + '.diff')} {LOG_FILE}")
        if state == 0:
            print(f"\n      {file} - OK.\\_________\n",)
        else:
            print(f"\n      {file} - ERROR.\\_________\n",)
        system(f"{RM_BINARY} {LOG_FILE}")


if __name__ == "__main__":
    main()
