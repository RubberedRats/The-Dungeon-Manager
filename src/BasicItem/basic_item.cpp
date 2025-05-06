#include "basic_item.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

// NOTE: This class is not intended to be used in a scene. Use it in scripts only.

// Method binder
void BasicItem::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_name"), &BasicItem::get_name);
    ClassDB::bind_method(D_METHOD("get_type"), &BasicItem::get_type);
    ClassDB::bind_method(D_METHOD("get_desc"), &BasicItem::get_desc);
    ClassDB::bind_method(D_METHOD("get_rarity"), &BasicItem::get_rarity);
    ClassDB::bind_method(D_METHOD("get_value"), &BasicItem::get_value);
    ClassDB::bind_method(D_METHOD("get_quantity"), &BasicItem::get_quantity);
    ClassDB::bind_method(D_METHOD("get_tags"), &BasicItem::get_tags);

    ClassDB::bind_method(D_METHOD("set_name", "item_name"), &BasicItem::set_name);
    ClassDB::bind_method(D_METHOD("set_type", "item_type"), &BasicItem::set_type);
    ClassDB::bind_method(D_METHOD("set_desc", "desc"), &BasicItem::set_desc);
    ClassDB::bind_method(D_METHOD("set_rarity", "info"), &BasicItem::set_rarity);
    ClassDB::bind_method(D_METHOD("set_value", "info"), &BasicItem::set_value);
    ClassDB::bind_method(D_METHOD("set_quantity", "qty"), &BasicItem::set_quantity);
    ClassDB::bind_method(D_METHOD("set_tags", "item_tags"), &BasicItem::set_tags);

    ClassDB::bind_method(D_METHOD("add_tag", "tag"), &BasicItem::add_tag);
    ClassDB::bind_method(D_METHOD("remove_tag", "key"), &BasicItem::remove_tag);
    ClassDB::bind_method(D_METHOD("get_tag_text", "key"), &BasicItem::get_tag_text);

    ClassDB::bind_method(D_METHOD("generate_full_description"), &BasicItem::generate_full_description);
}

// Constructors/Destructors
BasicItem::BasicItem() {
    name = "";
    type = "";
    description = "";
    rarity = Common;
    value = 0;
    quantity = 0; 
    tags = Dictionary();
}

BasicItem::BasicItem(String item_name) {
    name = item_name;
    type = "";
    description = "";
    rarity = Common;
    value = 0.0;
    quantity = 0; 
    tags = Dictionary();
}

BasicItem::BasicItem(String item_name, String item_type, String desc, int r, double value, int qty, Dictionary item_tags) {
    name = item_name;
    type = item_type;
    description = desc;
    quantity = qty;
    tags = item_tags;

    switch (r) {
        case (0):
            rarity = Common;
            break;
        case (1):
            rarity = Uncommon;
            break;
        case (2):
            rarity = Rare;
            break;
        case (3):
            rarity = VeryRare;
            break;
        case (4):
            rarity = Legendary;
            break;
        case (5):
            rarity = Artifact;
            break;
        default:
            rarity = Common;
    }
}

BasicItem::~BasicItem() {

}

//  Getters / Setters
String BasicItem::get_name() {
    return name;
}
void BasicItem::set_name(String item_name) {
    name = item_name;
}

String BasicItem::get_type() {
    return type;
}
void BasicItem::set_type(String item_type) {
    type = item_type;
}

String BasicItem::get_desc() {
    return description;
}
void BasicItem::set_desc(String desc) {
    description = desc;
}

String BasicItem::get_rarity() {
    switch (rarity) {
        case (0):
            return "Common";
        case (1):
            return "Uncommon";
        case (2):
            return "Rare";
        case (3):
            return "VeryRare";
        case (4):
            return "Legendary";
        case (5):
            return "Artifact";
        default:
            return "Common";
    }
}
void BasicItem::set_rarity(int r) {
    switch (r) {
        case (0):
            rarity = Common;
            break;
        case (1):
            rarity = Uncommon;
            break;
        case (2):
            rarity = Rare;
            break;
        case (3):
            rarity = VeryRare;
            break;
        case (4):
            rarity = Legendary;
            break;
        case (5):
            rarity = Artifact;
            break;
        default:
            rarity = Common;
    }
}

double BasicItem::get_value() {
    return value;
}
void BasicItem::set_value(double val) {
    value = val;
}

int BasicItem::get_quantity() {
    return quantity;
}
void BasicItem::set_quantity(int qty) {
    quantity = qty;
}

Dictionary BasicItem::get_tags() {
    return tags;
}
void BasicItem::set_tags(Dictionary item_tags) {
    tags = item_tags;
}

// Tag management
void BasicItem::add_tag(Dictionary tag) {
    tags.assign(tag);
}
void BasicItem::remove_tag(String key) {
    tags.erase(key);
}
String BasicItem::get_tag_text(String key) {
    return tags[key];
}

// Quantity management
void BasicItem::inc_quantity(int amt) {
    quantity += amt;
}
void BasicItem::dec_quantity(int amt) {
    quantity -= amt;
    quantity = (quantity < 0) ? 0 : quantity;
}

// Description generator
String BasicItem::generate_full_description() {
    String output = String();
    String temp_key;
    for (int i = 0; i < tags.keys().size(); i++) {
        temp_key = tags.keys()[i];
        output += (temp_key + ": " + UtilityFunctions::str(tags[temp_key]) + "\n");
    }

    return output;
}

// Process
void BasicItem::_process(double delta) {

}
