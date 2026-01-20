#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>
#include <bn_random.h>


int main()
{

    bn::core::init();
    bn::random rng;
    bn::backdrop::set_color(bn::color(6, 18, 31));
    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(17, 32);
    bn::vector<bn::sprite_ptr, 1000> circles = {};
    for (int y = -40; y <= 40; y += 15) {
    for(int x = -40; x <= 40; x += 15) {
    bn::sprite_ptr myCircleLines = bn::sprite_items::dot.create_sprite(x, y);
    circles.push_back(myCircleLines);
    }
     
    
}

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
        else if (bn::keypad::down_pressed()) {
        int x = rng.get_int(-40,41);
         int y= rng.get_int(-40,41);  
        bn::sprite_ptr myRngCirle = bn::sprite_items::dot.create_sprite(x, y);
        circles.push_back(myRngCirle);

    }

        bn::core::update();
    }
}