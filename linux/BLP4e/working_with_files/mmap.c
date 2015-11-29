/**
 * mmap.c
 * Using mmap
 * Compilation: gcc -o mmap mmap.c
 * Created: 2015-11-16
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

/*
 * The mmap (for memory map) function sets up a segment of memory that can be
 * read or written by two or more programs. Changes made by one program are seen
 * by the others.
 * The mmap function creates a pointer to a region of memory associated with the
 * contents of the file accessed through an open file descriptor.
 * -----------------------------------------------------------------------------
 *  #include <sys/mman.h>
 *  void *mmap(void *addr, size_t len, int prot, 
 *             int flags, int fildes, off_t off);
 *  int msync(void *addr, size_t len, int flags);
 *  int munmap(void *addr, size_t len);
 * -----------------------------------------------------------------------------
 * Parameters:
 *  addr:   parameter to request a particular memory address. If it's zero, the
 *          resulting pointer is allocated automatically. This is the recommended
 *          usage, because it is difficult to be portable otherwise.
 *  len:    parameter to set the length of the memory segment.
 *  prot:   parameter to set access permissions for the memory segment. This is
 *          the bitwise OR of the following constant values:
 *              PROT_READ:  The segment can be read
 *              PROT_WRITE: The segment can be written
 *              PROT_EXEC:  The segment can be executed
 *              PROT_NONE:  The segment can't be accessed
 *  flags:  controls how changes made to the segment by the program are
 *          reflected elsewhere;
 *              MAP_PRIVATE The segment is private, changes are local
 *              MAP_SHARED  The segment changes are made in the file
 *              MAP_FIXED   The segment must be at the given address, addr
 *  fildes: the open file descriptor
 *  off:    the start of the file data
 * Return value
 *  Returns the pointer to the memory segment on success.
 *  Returns MAP_FAILED ((void *) 0) on failure.
 *
 *
 * The msync function causes the changes in part or all of the memory segment to
 * be written back to (ro read from) the mapped file.
 * Parameters
 *  addr:   The start address of the segment to updated
 *  len:    The length of the segment to be updated
 *  flags:  Controls how the update should be performed using the options shown
 *          in the following:
 *              MS_ASYNC        Perform asynchronous writes
 *              MS_SYNC         Perform synchronous writes
 *              MS_INVALIDATE   Read data back in from the file
 *
 * The munmap function releases the memory segment.
 * Return value
 *  Returns 0 on success, -1 on failure.
 */

typedef  struct {
    int integer;
    char string[24];
} RECORD;

#define NRECORDS (100)

int main()
{
    RECORD record, *mapped;
    int i, f;
    FILE *fp;

    // create NRECORDS records appended to the file records.dat
    fp = fopen("records.dat", "w+");
    for (i = 0; i < NRECORDS; ++i) {
        record.integer = i;
        sprintf(record.string, "RECORD-%d", i);
        fwrite(&record, sizeof(record), 1, fp);
    }
    fclose(fp);

    // change the integer value of record 43 to 143 and write this to the 43rd
    // records' string
    fp = fopen("records.dat", "r+");
    fseek(fp, 43*sizeof(record), SEEK_SET);
    fread(&record, sizeof(record), 1, fp);
    record.integer = 143;
    sprintf(record.string, "RECORD-%d", record.integer);
    fseek(fp, 43*sizeof(record), SEEK_SET);
    fwrite(&record, sizeof(record), 1, fp);
    fclose(fp);

    // map the records into memory and access the 43rd record;
    // and change the integer to 243 (and update the record string)
    f = open("records.dat", O_RDWR);
    mapped = (RECORD *) mmap(0, NRECORDS*sizeof(record),
                             PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    mapped[43].integer = 243;
    sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);
    msync(mapped, NRECORDS*sizeof(record), MS_ASYNC);
    munmap(mapped, NRECORDS*sizeof(record));
    close(f);

    exit(0);
}
