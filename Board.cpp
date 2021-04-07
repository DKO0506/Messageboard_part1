#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "Board.hpp"

namespace ariel{

    constexpr int OFF_STATE = 1;

    unsigned int Board::number_of_cols(){
        if(my_board.empty()){
            return 0;
        }
        return my_board[0].size();
    }

    void Board::insert_row(unsigned int add_row){
        string empty(number_of_cols(),'_');
        my_board.resize(my_board.size() + add_row,empty);
    }

    void Board::insert_col(unsigned int add_col){
        for(unsigned int i = 0;i< my_board.size();i++){
            my_board[i] += string(add_col,'_');
        }
    }
    
    void Board::post(unsigned int row,unsigned int col,Direction direction,string str){

        unsigned int max_row = row + OFF_STATE;

        if(direction == Direction::Vertical){
            max_row += str.size();
        }
        if(max_row > my_board.size()){
            insert_row(max_row - my_board.size());
        }
        unsigned int max_col = col + OFF_STATE ;
        if(direction == Direction::Horizontal){
            max_col += str.size();
        }
        if(max_col > number_of_cols()){
            insert_col(max_col - number_of_cols());
        }

        if(direction == Direction::Horizontal){
            for(unsigned int i = 0; i < str.size();i++){
                my_board[row][i + col] = str[i];
            }
        }else{
            for(unsigned int i = 0;i<str.size();i++){
                my_board[i + row][col] = str[i];
            }
        }
    }

    string Board::read(unsigned int row,unsigned int col,Direction direction,unsigned int n){
        string answer;

        if(direction == Direction::Horizontal){
            if(row >= my_board.size()){
                answer = string(n,'_');
            }else{
                size_t read_max_col = col + n;
                for(unsigned int i =col;i < min(read_max_col,my_board[row].size());i++){
                    answer += my_board[row][i];
                }
            }
        }else{
            if (col >= number_of_cols()){
                answer = string(n,'_');
            } else{
                size_t read_max_row = row + n;
                for(unsigned int i=row;i < min<size_t>(read_max_row,my_board.size());i++){
                    answer += my_board[i][col];
                }
            }
        }
        if(answer.size() < n){
            answer += string(n- answer.size(),'_');
        }

        return answer;
    }

    void Board::show(){
        
    }

}