#include <iostream>
#include "Search_algs.cpp"
#include "Chess.cpp"

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=10;

    std::cout<< fibbonachi(arr, 3, size)<<endl;
    std::cout<< binarySearch(arr, 7, size)<<endl;
    std::cout<< interpolation(arr, 5, size)<<endl;
    std::cout<<endl;

    chess table;

    vector<figure> board;

    board = table.solve();
    table.printBoard(board);
    for (auto i: board)
        cout<<i.getx()<<" "<<i.gety()<<"; ";
}