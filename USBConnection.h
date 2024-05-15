
#ifndef USBCONNECTION_H
#define USBCONNECTION_H
#include <stack>

class USBConnection {
 private:
  int ID;

 public:
  static std::stack<int> ids;

  USBConnection();
  int get_id();
  static USBConnection* CreateUsbConnection() {
    return ids.empty() ? nullptr : new USBConnection;
  }
  ~USBConnection();
};

#endif  // !USBCONNECTION_H
