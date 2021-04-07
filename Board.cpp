#include "Board.hpp"
#include <iostream>
using namespace std;

namespace ariel{
    void Board::post(uint row,uint column,Direction direction,std::string const &ad )
    {
        //post empty ad do nothing
        if(ad.length()==0){
            return;
        }
        //save the min row that we post in 
        if(row<minRow)
        {
          minRow=row;
        }
        //save the min column that we post in
        if(column<minColumn)
        {
           minColumn=column;
        }
        switch(direction)
        {
        //the direction of the post is post horizontal
         case(Direction::Horizontal):
         {
             //save the bigest row that we post on
            if(row>maxRow)
            {
                maxRow=row;
            }
            //save the bigest column that we post on
            if(column+ad.length()>maxColumns)
            {                
                maxColumns=column+ad.length()-1;
            }
            //Inserts the message to the map
            for(uint i=0;i<ad.length();i++)
            {
                board[row][column+i]=ad.at(i);
            }
            break;
         }
         case(Direction::Vertical):
         {
             //save the max row we post in
            if(row+ad.length()>=maxRow)
            {
                maxRow=row+ad.length()-1;
            }
            //save the maxColumn we post in
            if(column>maxColumns)
            {
                maxColumns=column;
            }
            //Inserts the message to the map
            for(uint i=0;i<ad.length();i++)
            {
                board[row+i][column]=ad.at(i);
            }
            break;
         }
         default:
             return;
        }

    }
    string Board::read(uint row,uint column,Direction direction,uint len)
    {
        string ans;
        switch(direction)
        {
            //read horizontal direction
            case(Direction::Horizontal):
            {
                //read the post from the map
                for(uint i=0;i<len;i++)
                {
                    //if the place is empty add to ans the post _
                    if((board[row][column+i])==0){
                        ans+="_";
                    }
                    //add the char in this place to ans
                    else {
                        ans+=board[row][column+i];
                    }
                }
                break;
            }
            //read vertical direction
            case(Direction::Vertical):
            {
                for(uint i=0;i<len;i++)
                {
                    //if the pkace we reading is empty add _ to ans
                    if((board[row+i][column])==0){
                        ans+="_";
                    }
                    //add the char in this place to ans
                    else{ 
                        ans+=board[row+i][column];
                    }
                }
                break;
            }
            default:
                return "";
        }
        return ans;
    }

    void Board::show(){
        //print the board from the min place we post in to the max place we post in
        for(uint i=minRow;i<=maxRow;i++)
        {
            for(uint j=minColumn;j<=maxColumns;j++)
            {
                if((board[i][j])==0){
                        cout<<"_";
                }
                cout<<board[i][j];
            }
            cout<<""<<endl;
        }

    }
}