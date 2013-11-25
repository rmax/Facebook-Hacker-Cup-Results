#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int start, end, startl, endl;
  int invalid;
  int T, N;
  int i, j, k;
  char *buf = malloc(21);
  fscanf(stdin, "%d", &T);
  for (k = 0; k < T; ++k) {
    //read in line length
    fscanf(stdin, "%d", &N);
    start = -1;
    end = -1;
    endl = -1;
    invalid = 0;
    for (j = 0; j < N; ++j) {
      fscanf(stdin, "%s", buf);
      // We are looking at line j
      if (start == -1) {
	// Since we haven't established start, all previous lines were empty
	for (i = 0; i < N; ++i) {
	  if (buf[i] == '#') {
	    // start established
	    startl = j;
	    start = i;
	    break;
	  }
	}
	if (start != -1) {
	  for (; i < N; ++i) {
	    if (buf[i] == '.')
	      break;
	  }
	  end = i;
	}
	for (; i < N; ++i) {
	  if (buf[i] == '#')
	    invalid = 1;
	}
	// If end is not N, make sure the rest of the array is right
      }
      else {
	if (endl == -1) {
	  // Since we haven't found the end, check whether it satisfies the
	  // same properties as before
	  for (i = 0; i < start; ++i)
	    if (buf[i] != '.')
	      invalid = 1;
	  for (; i < end; ++i)
	    if (buf[i] != '#') {
	      // Check whether the entire line is empty
	      endl = j;
	    }
	  for (; i < N; ++i)
	    if (buf[i] != '.')
	      invalid = 1;
	}
	else {
	  // Check whether the entire line is empty
	  for (i = 0; i < N; ++i)
	    if (buf[i] != '.')
	      invalid = 1;
	}
      }
    }
    if (startl != -1 && endl == -1)
      endl = N; // wouldn't have been set otherwise
    if (invalid || ((end - start) != (endl - startl))) {
      printf("Case #%d: %s\n", k+1, "NO");
    }
    else {
      printf("Case #%d: %s\n", k+1, "YES");
    }
  }
  free(buf);
}
