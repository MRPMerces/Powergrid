//#include "Cities.h"
//
//string Cities::get_name() const{
//	return name;
//}
//
//void Cities::set_name(string n) {
//	name = n;
//}
//
//int Cities::get_id() const{
//	return id;
//}
//
//void Cities::set_id(int i) {
//	id = i;
//}
//
//int Cities::get_section() const{
//	return section;
//}
//
//void Cities::set_section(int s) {
//	section = s;
//}
//
//vector <Player> Cities::get_vec_citySlots() const {
//	return vec_citySlots;
//}
//
//void Cities::set_vec_citySlots(Player p) {
//	if (vec_citySlots.size() <= 3 && p.get_money() >= vec_citySlots.size() * 5 + 5) {
//		p.add_money(-(vec_citySlots.size() * 5 + 5));
//		vec_citySlots.push_back(p);
//	}
//}
//
//vector <Edge> Cities::get_Edges() {
//	return vec_neighbouringCities;
//}
//
//void Cities::set_Edge(Edge e) {
//	vec_neighbouringCities.push_back(e);
//}
