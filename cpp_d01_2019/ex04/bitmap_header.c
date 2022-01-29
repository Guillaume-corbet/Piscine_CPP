/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** bitmap_header
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    int size_file = 0;
    int offset_file = 54;
    uint16_t magic = 0x424D;

    header->magic = ((magic>>8) | (magic<<8));
    size_file = 40 + (size * size * 4) + 14;
    header->size = size_file;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = offset_file;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}
