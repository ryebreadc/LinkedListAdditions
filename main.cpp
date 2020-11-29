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
    void setItem(const char* value) {
      item = value;
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

    void insert_position(int pos, const char* value) {
      ListItem *cur;
      ListItem *temp = new ListItem(value);
      cur = first_item;
      for (int i=1; i < pos; i++) {
        cur = cur -> nextItem();
      }
      temp->setNextItem(cur->nextItem());
      cur->setNextItem(temp);
      cur = cur -> nextItem();
    }

    void item_position(int pos) {
      ListItem *cur;
      cur = first_item;
      for (int i = 0; i < pos; i++) {
        cur = cur -> nextItem();
      }
      cout << cur->view() << endl;
    };

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
  l.insert_position(2, "Ryan");
  l.outputList();
  l.item_position(2);


}