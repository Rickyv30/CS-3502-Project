//
// Created by User on 2019-04-23.
//

#include "PAGE_TABLE.h"


namespace Project_Phase_One{
    PAGE_TABLE::PAGE_TABLE() {


    }
    PAGE_TABLE::PAGE_TABLE(int psize, int page_base_table) {

        this->page_size = psize;
        this->page_base_table = page_base_table;

    }
    PAGE_TABLE::PAGE_TABLE(int psize, int page_base_table, int pID) {

        this->page_size = psize;
        this->page_base_table = page_base_table;
        this->pID = pID;

    }



}