#include "Simple_window.h"
#include "emoji.hpp"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 100;

int main()
{
    using namespace Graph_lib;
    
    const Point tl{100, 100};
    const string win_label{"Emoji factory"};
    Simple_window win{tl, xmax, ymax, win_label};
    
    SmileyFace smileyBoye{{tl.x, tl.y}, emojiRadius};
    smileyBoye.attach_to(win);
    
    SadFace sadBoye{{tl.x + 2*emojiRadius + emojiRadius/5, tl.y}, emojiRadius};
    sadBoye.attach_to(win);
    
    AngryFace angryBoye{{tl.x + 4*emojiRadius + 2*emojiRadius/5, tl.y}, emojiRadius};
    angryBoye.attach_to(win);
    
    BlinkingFace blinkyBoye{{tl.x, tl.y + 2*emojiRadius + emojiRadius/5}, emojiRadius};
    blinkyBoye.attach_to(win);  
    
    SurprisedFace surprisedBoye{{tl.x+ 2*emojiRadius + emojiRadius/5, tl.y + 2*emojiRadius + emojiRadius/5}, emojiRadius};
    surprisedBoye.attach_to(win);
    
    win.wait_for_button();
}
