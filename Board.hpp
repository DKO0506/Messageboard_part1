#include <string>
#include <vector>
#include "Direction.hpp"


namespace ariel{

    using namespace std;

    class Board{
    public:
        void post(unsigned int row,unsigned int col,Direction direction,string str);
        string read(unsigned int row,unsigned int col,Direction direction,unsigned int n);
        void show();
    private:
        vector<string> my_board;
        unsigned int number_of_cols();
        void insert_row(unsigned int add_row);
        void insert_col(unsigned int add_col);
    };
}