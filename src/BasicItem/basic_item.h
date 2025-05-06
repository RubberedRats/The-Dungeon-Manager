#ifndef BASIC_ITEM_H
#define BASIC_ITEM_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>

namespace godot {

using namespace godot;

enum Rarity {
    Common,
    Uncommon,
    Rare,
    VeryRare,
    Legendary,
    Artifact
};

class BasicItem : public Node {
GDCLASS(BasicItem, Node)

private:
    String name;
    String type;
    String description;
    enum Rarity rarity;

    double value;
    int quantity;

    Dictionary tags;

protected:
    static void _bind_methods();

public:
    BasicItem();
    BasicItem(String item_name);
    BasicItem(String item_name, String item_type, String desc, int r, double val, int qty, Dictionary item_tags);
    ~BasicItem();

    String get_name();
    void set_name(String item_name);

    String get_type();
    void set_type(String item_type);

    String get_desc();
    void set_desc(String desc);

    String get_rarity();
    void set_rarity(int r);

    double get_value();
    void set_value(double val);

    int get_quantity();
    void set_quantity(int qty);

    Dictionary get_tags();
    void set_tags(Dictionary item_tags);

    void add_tag(Dictionary tag);
    void remove_tag(String key);
    String get_tag_text(String key);

    void inc_quantity(int amt);
    void dec_quantity(int amt);

    String generate_full_description();

    void _process(double delta) override;

};

}

#endif