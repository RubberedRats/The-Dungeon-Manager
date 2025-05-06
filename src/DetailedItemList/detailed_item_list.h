#ifndef DETAILED_ITEM_LIST_H
#define DETAILED_ITEM_LIST_H

#include <godot_cpp/classes/item_list.hpp>
#include <godot_cpp/variant/array.hpp>

namespace godot {
    
using namespace godot;

class DetailedItemList : public ItemList {
GDCLASS(DetailedItemList, ItemList)

private:
    Array LootDrops;

protected:
    static void _bind_methods();

public:
    DetailedItemList();
    ~DetailedItemList();

    // Overloads and Overrides

    void print_entries();
    void push_entry(const Array& entry);
    void remove_entry(const int index);
    void clear_entries();

    Array get_entries();
    void set_entries(const Array& entry);

    void _process(double delta) override;
};

}

#endif