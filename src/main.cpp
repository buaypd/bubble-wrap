#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>


int main()
{
    bn::core::init();
    //bn::backdrop::set_color(bn::color(20, 20, 31)); // pld color
    //bn::backdrop::set_color(bn::color(200,88,51)); out of bound :(
    bn::backdrop::set_color(bn::color(6, 18, 31));
    while (true)
    {
        bn::core::update();
    }
}