from os import listdir, system, path


MAKER = "make"
BINARY = "./scop"
DIFF_BINARY = "diff"
RM_BINARY = "rm -f"
TESTS_PATH = path.join("data", "tests")
DIFFS_PATH = path.join(TESTS_PATH, "diffs")
LOG_FILE = path.join(TESTS_PATH, "test_log")
EXCLUDED_FILES = ["test_log", "test_code.py"]


def main():
    ok = 0
    error = 0
    test_files = [f for f in sorted(listdir(TESTS_PATH)) if f not in EXCLUDED_FILES and path.isfile(path.join(TESTS_PATH, f))]
    system(MAKER)
    for file in test_files:
        print(f"\n\n\033[01m_________/ File: {file}\033[00m\n")
        system(f"{BINARY} {path.join(TESTS_PATH, file)} > {LOG_FILE}")
#        system(f"{BINARY} {path.join(TESTS_PATH, file)} > {path.join(DIFFS_PATH, file + '.diff')}")
#        this line set ALL the diffs files content with the current SCOP output.
        state = system(f"{DIFF_BINARY} {path.join(DIFFS_PATH, file + '.diff')} {LOG_FILE}")
        if state == 0:
            print(f"\033[42m                 {file} - OK.\\_________\033[00m\n",)
            ok += 1
        else:
            print(f"\n\033[41m                 {file} - ERROR.\\_________\033[00m\n",)
            error += 1
    print(f"\n\n\033[01mSummary: \033[00m\n")
    print(f"\033[42mOK\033[00m {ok}\n")
    print(f"\033[41mERROR\033[00m {error}\n")
    system(f"{RM_BINARY} {LOG_FILE}")


if __name__ == "__main__":
    main()
