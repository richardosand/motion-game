#include "rubymotion.h"
#include "motion-game.h"

VALUE rb_cMenu = Qnil;

/// @class Menu < Object
/// A Menu is a way to navigate through game options.
/// Menus often contain options like Play, Quit, Settings and About.
/// This is usually in the form of buttons that are pressed.
static VALUE
menu_alloc(VALUE rcv, SEL sel)
{
    cocos2d::Menu *menu = cocos2d::Menu::create();
    return rb_cocos2d_object_new(menu, rcv);
}

/// @method #align_items_vertically(padding=null)
/// aligns menu items vertically with padding
/// (call after adding items via image_item)
/// @param padding [Float] the amount of padding between the items.
/// @return [self] the receiver.
static VALUE
menu_align_items_vertically(VALUE rcv, SEL sel, int argc, VALUE *argv)
{
    VALUE padding = Qnil;
    rb_scan_args(argc, argv, "01", &padding);

    if (padding != Qnil) {
	MENU(rcv)->alignItemsVerticallyWithPadding(NUM2LONG(padding));
    }
    else {
	MENU(rcv)->alignItemsVertically();
    }

    return rcv;
}

/// @method #align_items_horizontally(padding=null)
/// aligns menu items horizontally with padding
/// (call after adding items via image_item)
/// @param padding [Float] the amount of padding between the items.
/// @return [self] the receiver.
static VALUE
menu_align_items_horizontally(VALUE rcv, SEL sel, int argc, VALUE *argv)
{
    VALUE padding = Qnil;
    rb_scan_args(argc, argv, "01", &padding);

    if (padding != Qnil) {
	MENU(rcv)->alignItemsHorizontallyWithPadding(NUM2LONG(padding));
    }
    else {
	MENU(rcv)->alignItemsHorizontally();
    }

    return rcv;
}

/// @method #enabled?
/// Whether the menu is enabled. When enabled, a menu can be
/// touched or clicked. By default, a menu is enabled.
/// @return [Boolean] whether the menu is enabled.
static VALUE
menu_enabled(VALUE rcv, SEL sel)
{
    return MENU(rcv)->isEnabled() ? Qtrue : Qfalse;
}

/// @method #enabled=(value)
/// Enable or disable a menu item.
/// @param value [Boolean] true if enable an item.

static VALUE
menu_enabled_set(VALUE rcv, SEL sel, VALUE val)
{
    MENU(rcv)->setEnabled(RTEST(val));
    return val;
}

/// @method #image_item(normal_image, selected_image)
/// Create a menu item with a normal and selected images.
/// @param normal_image [String] normal image name.
/// @param selected_image [String] selected image name.
/// @yield The methods to call when tapped menu.
/// @return [self] the receiver.

static VALUE
menu_image_item(VALUE rcv, SEL sel, VALUE normal_image, VALUE selected_image)
{
    VALUE block = rb_current_block();
    if (block == Qnil) {
	rb_raise(rb_eArgError, "block not given");
    }
    block = rb_retain(block); // FIXME need release...

    cocos2d::MenuItemImage *item = cocos2d::MenuItemImage::create(
	RSTRING_PTR(StringValue(normal_image)), RSTRING_PTR(StringValue(selected_image)),
	[block](cocos2d::Ref *sender) {
	    rb_block_call(block, 0, NULL);
	});
    MENU(rcv)->addChild(item);
    return rcv;
}

extern "C"
void
Init_Menu(void)
{
    rb_cMenu = rb_define_class_under(rb_mMC, "Menu", rb_cNode);
    // rb_register_cocos2d_object_finalizer(rb_cMenu); removed because rb_cMenu inherits rb_cNode and it already has finalizer.

    rb_define_singleton_method(rb_cMenu, "alloc", menu_alloc, 0);
    rb_define_method(rb_cMenu, "enabled?", menu_enabled, 0);
    rb_define_method(rb_cMenu, "enabled=", menu_enabled_set, 1);
    rb_define_method(rb_cMenu, "image_item", menu_image_item, 2);
    rb_define_method(rb_cMenu, "align_items_horizontally", menu_align_items_horizontally, -1);
    rb_define_method(rb_cMenu, "align_items_vertically", menu_align_items_vertically, -1);
}
