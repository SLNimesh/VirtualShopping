#include <iostream>
#include <list>

class Item{
    private:
        int barcode;
        std::string name;
        double itemPrice;

    public:
        Item(int);
        int getBarcode(){
            return this->barcode;
        }

        std::string getItemName(){
            return this->name;
        }

        double getPrice(){
            return this->itemPrice;
        }

};

Item::Item(int barcode){
    // SELECT itemName,price
    // FROM items
    // WHERE id=barcode;
    
    this->barcode=barcode;
    // this->name=itemName;
    // this->itemPrice=price;
}


class Cart{
    
    private:
        std::list <Item> cartItems;

    public:
        //ADD ITEMS TO CART
        bool addItem(Item& item){
            int barcode=item.getBarcode();
            //check for item availability in DB
            // SELECT COUNT(availableStock)
            // FROM stock
            // WHERE id=barcode;

            // if returned value > 0 then isAvailable=true;
            bool isAvailable=true;

            if(isAvailable){
                cartItems.push_back(item);
                std::cout<<"Item Added to Cart \n";
                return true;
            }
            return false;
        }

        //REMOVE ITEM FROM CART
        bool removeItem(Item item){
            bool inCart=false;
            for(Item i:cartItems){
                if(i.getBarcode()==item.getBarcode()){
                    inCart=true;
                    break;
                }
            }
            if(inCart){
                cartItems.remove(item);
                std::cout<<"Item removed from cart \n";
                return true;
            }
            return false;
        }

        //CALCULATE CART TOTAL
        double cartTotal(Buyer buyer){
            double cartTotal=0;
            if(!cartItems.empty()){
                for(Item i:cartItems){
                    cartTotal+=i.getPrice();
                }
            }
            return cartTotal;
        }
};


class Buyer{
    private:
        std::string userName;
        Cart myCart;
        //with userName call database for other info: email,address,card..

    public:
        Buyer(std::string);
        void myOrders(){
            //this->userName to call for existing orders in DB
            // SELECT *
            // FROM orders
            // WHERE buyer=this->userName;
        }
        Cart getMyCart(){
            return this->myCart;
        }
};

Buyer::Buyer(std::string username){
    this->userName=username;
    // this->myCart=new Cart();
    std::cout<<"Welcome user"<<username<<"\n";
}



class Seller{

};

int main(){
    std::cout<<"Hello World \n";
}