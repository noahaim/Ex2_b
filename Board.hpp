#include <string>
#include "Direction.hpp"
#include <map>
#define MAX_VALUE 4294967295
namespace ariel
{
    class Board{
        uint maxRow;
        uint maxColumns;
        uint minRow;
        uint minColumn;
        std::map<uint,std::map<uint,char>> board;
    public:
        Board(){
            maxRow=0;
            maxColumns=0;
            minRow=MAX_VALUE;
            minColumn=MAX_VALUE;
        }
        void post(uint row,uint column,Direction direction,std::string const &ad );
        std::string read(uint row,uint column,Direction direction,uint len);
        void show();
    };
}