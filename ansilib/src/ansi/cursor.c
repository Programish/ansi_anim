#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include <io.h>
#include <ansi/common.h>
#include <ansi/cursor.h>

point_t get_cursor_pos(void)
{
    point_t ret = { 0 };
    uint32_t line, column;

    /* ESC[6n   request cursor position ( reports as ESC[#;#R ) */

    printmsg(CSI"6n");
    if ( scanmsg(CSI"%"PRIu32";%"PRIu32"R", &line, &column) ) {

        ret.x = column;
        ret.y = line;
    }

    return ret;
}

void move_cursor(point_t pos)
{
    /*
     * ESC[{line};{column}H
     * or
     * ESC[{line};{column}f
     */

    printmsg(CSI"%i;%iH", pos.y, pos.x);
}

void nudge_cursor(dir_t direction, uint32_t step)
{
    /* TODO: `direction` is a bitmask */
    char end_ch;

    /*
     * ESC[#A   moves cursor up # lines
     * ESC[#B   moves cursor down # lines
     * ESC[#C   moves cursor right # columns
     * ESC[#D   moves cursor left # columns
     */

    switch ( direction ) {
        case UP:    end_ch = 'A'; break;
        case DOWN:  end_ch = 'B'; break;
        case RIGHT: end_ch = 'C'; break;
        case LEFT:  end_ch = 'D';
    }

    printmsg(CSI"%i%c", step, end_ch);
}
