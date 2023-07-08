/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

In Unix-style file system:
A period '.' refers to the current directory.
A double period '..' refers to the directory up a level.
Any multiple consecutive slashes '//' are treated as a single slash '/'.

In Simplified Absolute path:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path doesn't end with trailing slashes '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
The path will not have whitespace characters.

Input :
A = "/home/"

Output :
"/home"

Input :
A = "/a/./b/../../c/"

Output :
"/c"

*/

#include <stdio.h>
#include <string.h>

// function to simplify a Unix-styled absolute path
void simplify(char A[], char res[], int n)
{
	// stack to store the file's names.
	char st[1000][1000];
	int top = -1;

	// temporary string which stores the extracted
	// directory name or commands("." / "..")
	// Eg. "/a/b/../."
	// dir will contain "a", "b", "..", ".";
	char dir[1000];

	// every string starts from root directory.
	strcpy(res, "/");
	int len_A = strlen(A);

	for (int i = 0; i < len_A; i++) {

		// we will clear the temporary string
		// every time to accommodate new directory
		// name or command.
		int dir_idx = 0;

		// skip all the multiple '/' Eg. "/////""
		while (A[i] == '/')
			i++;

		// stores directory's name ("a", "b", etc.)
		// or commands ("."/"..") into dir
		while (i < len_A && A[i] != '/') {
			dir[dir_idx++] = A[i];
			i++;
		}
		dir[dir_idx] = '\0';

		// if dir has ".." just pop the topmost
		// element if the stack is not empty
		// otherwise ignore.
		if (strcmp(dir, "..") == 0) {
			if (top != -1)
				top--;
		}

		// if dir has "." then simply continue
		// with the process.
		else if (strcmp(dir, ".") == 0)
			continue;

		// pushes if it encounters directory's
		// name ("a", "b").
		else if (dir_idx != 0) {
			strcpy(st[++top], dir);
		}
	}

	// construct the simplified path from the stack.
	int res_idx = 1; // Start from index 1 to avoid leading "/"
	for (int i = 0; i <= top; i++) {
		if (i != top) {
			strcat(res, st[i]);
			strcat(res, "/");
		} else {
			strcat(res, st[i]);
		}
	}
}

int main()
{
	// absolute path which we have to simplify.
	char str[] = "/home//user/.././documents/";
	char res[1000];
	simplify(str, res, sizeof(res));
	printf("%s\n", res);
	return 0;
}

/*
This program takes the  path as a string, processes it using a stack, and then returns the simplified absolute path.
*/
