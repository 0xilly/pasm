#include <interp/Scan.hh>

#include <Defs.hh>

#include <stdio.h>

Scan::Scan(const char* target) {
  size len;
  FILE *fptr;
  fptr = fopen(target, "rb");
  char* buf;
  if (!fptr) {  
    Panic(fmt::format("No File: {} is found!", target));
  }

  size bsize;

  fseek(fptr, 0L, SEEK_END);
  bsize = ftell(fptr);
  rewind(fptr);

  if (bsize == 0) {
    fclose(fptr);
    free(buf);
    Panic(fmt::format("Empty file: {}\n", target));
  }

  buf = (char*)calloc(1, bsize + 1);

  if (!buf) {
    fclose(fptr);
    free(buf);
    Panic("Unable to allocate memory to file buffer\n");
  }

  if (1 != fread(buf, bsize, 1, fptr)) {
    fclose(fptr);
    free(buf);
    Panic(fmt::format("Failed to read {}\n", target));
  }

  fclose(fptr);

  this->buffer = buf;
  
}
