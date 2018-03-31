#ifndef FILEINPUT_H_
#define	FILEINPUT_H_

#include "../Headers/studentaiInfo.h"
#include <vector>
#include <list>
#include <deque>

void read_data(std::vector<studentaiInfo>& );
void read_data_test(std::vector<studentaiInfo>& ); 
void read_data_test(std::list<studentaiInfo>& );
void read_data_test(std::deque<studentaiInfo>& );
void write_data(std::vector<studentaiInfo> ); 
bool compareNames(const studentaiInfo&, const studentaiInfo&); 

#endif