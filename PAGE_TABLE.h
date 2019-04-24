//
// Created by User on 2019-04-23.
//

#ifndef PROJECT_1_PAGE_TABLE_H
#define PROJECT_1_PAGE_TABLE_H

namespace Project_Phase_One {
    class PAGE_TABLE {
    public:
        PAGE_TABLE();
        PAGE_TABLE(int psize, int page_base_table);
        PAGE_TABLE(int psize, int page_base_table, int pID);
        void find_free_frame();
    private:
        int pID;
        int number_of_Frame;
        bool is_Frame_full;
        int offset_count;
        int page_size;
        int page_base_table;
    };
}

#endif //PROJECT_1_PAGE_TABLE_H
