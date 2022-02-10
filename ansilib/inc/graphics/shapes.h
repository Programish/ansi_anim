#ifndef __GRAPHICS_SHAPES_H_
# define __GRAPHICS_SHAPES_H_

# include <stdint.h>

# include <graphics/common.h>

void draw_rectangle(const obj_style_t *, uint32_t width, uint32_t height,
                    char ch, char fill_ch);
void draw_triangle(const obj_style_t *, uint32_t height, char ch, char fill_ch);

#endif  /* __GRAPHICS_SHAPES_H_ */
