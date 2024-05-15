
#include "USBConnection.h"
std::stack<int> USBConnection::ids({3, 2, 1});
USBConnection::USBConnection() : ID(ids.top()) { ids.pop(); };
USBConnection::~USBConnection() { ids.push(this->ID); };
int USBConnection::get_id() { return this->ID; }
