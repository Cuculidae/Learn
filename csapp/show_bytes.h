/**
 * CSAPP: Chapter 2
 * Header file for show_bytes utility
 */

#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

typedef unsigned char byte;
typedef unsigned char *byte_pointer;
void show_bits(byte b);
void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_carray(char a[], int cnt);
void show_iarray(int a[], int cnt);
void show_sarray(char* a[], int cnt);

#endif
