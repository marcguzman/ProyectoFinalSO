#ifndef LDB_SCREEN_HPP
#define LDB_SCREEN_HPP
#include <LDB_color.hpp>
#include <LDB_types.hpp>

typedef enum LDB_SIDE{
                LDB_SIDE_BACKGROULDB,
                LDB_SIDE_FOREGROULDB
}LDB_SIDE;

namespace LDB{
        namespace Screen{
                        LDB_Color GetColor(LDB_SIDE side);
                        void SetColor(LDB_SIDE side, LDB_Color colour);
                        void PutChar(char c);
                        void PutString(const char* str);
                        void Clear(LDB_Color colour);
                        void SetCursor(uint8_t x, uint8_t y);
                        void itoa(unsigned int i);
                }
        }
#endif
