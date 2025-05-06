#include "detailed_item_list.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/print_string.hpp>

using namespace godot;

//Bind method
void DetailedItemList::_bind_methods() {
    ClassDB::bind_method(D_METHOD("print_entries"), &DetailedItemList::print_entries);
    ClassDB::bind_method(D_METHOD("push_entry", "entry"), &DetailedItemList::push_entry);
    ClassDB::bind_method(D_METHOD("remove_entry", "index"), &DetailedItemList::remove_entry);
    ClassDB::bind_method(D_METHOD("clear_entries"), &DetailedItemList::clear_entries);
    ClassDB::bind_method(D_METHOD("get_entries"), &DetailedItemList::get_entries);
    ClassDB::bind_method(D_METHOD("set_entries", "entry"), &DetailedItemList::set_entries);

    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "LootDrops"), "get_drops", "set_drops");
}

// Constructor
DetailedItemList::DetailedItemList() {
    LootDrops = Array();
}

// Destructor
DetailedItemList::~DetailedItemList() {

}

void DetailedItemList::print_entries() {
    print_line(LootDrops);
}

void DetailedItemList::push_entry(const Array& entry) {
    LootDrops.append(entry);
}

void DetailedItemList::remove_entry(const int index) {
    LootDrops.remove_at(index);
}

void DetailedItemList::clear_entries() {
    LootDrops.clear();
}

Array DetailedItemList::get_entries() {
    return LootDrops;
}

void DetailedItemList::set_entries(const Array& entry) {
    LootDrops = entry;
}

void DetailedItemList::_process(double delta) {
}


