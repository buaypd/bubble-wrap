#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(6, 18, 31));
    while (true)
    {
        if (bn::keypad::a_pressed())
        {
            bn::backdrop::set_color(bn::color(31, 21, 22));
        }
        else if (bn::keypad::b_pressed())
        {
            bn::backdrop::set_color(bn::color(20, 12, 26));
        }
        else if (bn::keypad::l_held() && bn::keypad::r_held())
        {
            bn::backdrop::set_color(bn::color(14, 8, 2));
        }

        bn::core::update();
    }
}