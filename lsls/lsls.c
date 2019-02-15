#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir_name;
  DIR *dp;
  struct dirent *ent;

  // Parse command line
  if (argc < 2)
  {
    // If there's no specified command, dir_name = current dir
    dir_name = ".";
  }
  else if (argc == 2)
  {
    dir_name = argv[1];
  }
  else
  {
    printf("Cannot open directory '%s'", argv[1]);
    return 1;
  }

  // Open directory
  dp = opendir(dir_name);

  // Repeatedly read and print entries
  while ((ent = readdir(dp)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(dp);
  return 0;
}