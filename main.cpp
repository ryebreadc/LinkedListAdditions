#include <iostream>
using namespace std;
class ListItem {
  
  private:

    const char* item;
    ListItem* next = nullptr;
    
  public:
    
    ListItem(const char *newItem) {
      item = newItem;
      next = nullptr;
    }

    ListItem* nextItem() {
      return next;
    }

    void setNextItem(ListItem* new_next) {
      next = new_next;
    }

    const char* view() {
      return item;
    }

};

class LinkedList {

  private:

    ListItem* first_item;
    int list_length;
  
    void deleteItem(ListItem* parent, ListItem* item) {
      parent->setNextItem(item->nextItem());
      delete item;
    }

  public:

    LinkedList(const char *newItem) {
      first_item = new ListItem(newItem);
      list_length = 1;
    }

    void addListItem(const char *newItem) {
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        current_item=next_item;
        next_item = current_item->nextItem();
      }
      current_item->setNextItem(new_item);
      list_length += 1;
    }

  

    int length() {
      return list_length;
    }

    void outputLength() {
      std::cout << length() << std::endl;
    }

    void outputList() {
      std::cout << first_item->view() << std::endl;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }



    int findItemMatching(const char* item) {
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      int i = 0;
      while (next_item != nullptr) {
        if(current_item->view() == item) {
          return i;
        }
        current_item=next_item;
        next_item = current_item->nextItem();
        i++;
      }
    }

};

int main() {
  LinkedList l("sam");
  l.outputList();
  l.outputLength();
  l.addListItem("bob");
  l.addListItem("tony");
  l.addListItem("paul");
  l.outputList();
  l.outputLength();
  l.findItemMatching("paul");
  
}