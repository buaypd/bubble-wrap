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
    bn::sprite_ptr myCircle  = bn::sprite_items::dot.create_sprite(55, 57);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(65, 55);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(75, 52);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(85, 55);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(95, 57);
    bn::sprite_ptr leftEye  = bn::sprite_items::dot.create_sprite(65, 32);
    bn::sprite_ptr rightEye = bn::sprite_items::dot.create_sprite(85, 32);

    bn::vector<bn::sprite_ptr, 1000> circles = {};
    for (int y = -40; y <= 40; y += 15) {
    for(int x = -40; x <= 40; x += 15) {
    bn::sprite_ptr myCircleLines = bn::sprite_items::dot.create_sprite(x, y);
    circles.push_back(myCircleLines);
    }
    circles[0].set_scale(2.5);
    circles[1].set_scale(5.0);
    circles[2].set_horizontal_scale(4.5);
    circles[3].set_vertical_scale(4.5);
    circles[4].set_shear(0.4);
    circles[5].set_rotation_angle(45);
    
     //bn::sprite_palette_ptr blue_palette = bn::sprite_items::dot.palette_item().create_palette();
     //blue_palette.set_color(1, bn::color(0,0,31));

     //for (size_t i = 0; i < circles.size(); i++)
     //{
      // circles[i].set_palette(blue_palette);
     //}
     
    
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