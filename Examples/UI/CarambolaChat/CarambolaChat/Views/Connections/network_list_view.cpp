
#include "precomp.h"
#include "network_list_view.h"
#include "network_list_item_view.h"

using namespace clan;

NetworkListView::NetworkListView()
{
	items = std::make_shared<View>();
	items->box_style.set_layout_block();
	items->box_style.set_margin(0.0f, 15.0f);
	items->box_style.set_background(Colorf::white); // Bug: required to make the border work
	items->box_style.set_border(Colorf::gray80, 0.0f, 0.0f, 0.0f, 1.0f);
	add_subview(items);

	auto add_button = std::make_shared<ButtonView>();
	add_button->label()->set_text("Add Network");
	add_button->label()->text_style().set_font("Segoe UI", 13.0f, 16.0f);
	add_button->label()->text_style().set_color(Colorf::navy);
	add_subview(add_button);
}

std::shared_ptr<NetworkListItemView> NetworkListView::add_item(const std::string &name)
{
	auto network = std::make_shared<NetworkListItemView>();
	network->set_name(name);
	items->add_subview(network);
	return network;
}