#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

void SplitString(const string& s, vector<string>& v, const string& c)
{
  string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}


int main(){
    vector<int> lib = {};
    string input;
    cin >> input;
    vector<string> class_set;
    SplitString(input, class_set, ";");

    lib.resize(class_set.size());



    // vector<int>
    //     nums = {};
    return 0;
}


/*
actor_周杰|周杰伦|张三;song_abc|ycd|xcde
请播放周杰伦的abc
**/
/**
#coding=utf-8

input_str = input()
comd = input()
result = ''

input_str_list = input_str.split(';')

input_type_dicts = []
value_lib = []
for item in input_str_list:
    valid_index = item.find('_') + 1;
    attr = item[0: valid_index - 1]
    value_lib.append(item[valid_index:])
    value_list = item[valid_index:].split('|')
    input_type_dicts.append({})
    for v in value_list:
        input_type_dicts[-1][v] = attr

i = 0
while i < len(comd):
    arr_index = 0
    for val_lib in value_lib:
        inx = val_lib.find(comd[i])
        if inx != -1 :
            res_ls = []
            while(inx != -1):
                j = i
                res = ''
                while(comd[j] == val_lib[inx]):
                    res += comd[j]
                    j += 1
                    inx += 1
                res_ls.append(res)
                tmp = val_lib[inx:].find(comd[i])
                if tmp != -1:
                    inx = inx + tmp
                else:
                    break
            max_index = 0
            max_len = len(res_ls[0])
            m = 0
            for rl in res_ls:
                if len(rl) > max_len:
                    max_index = m
                m += 1

            result += ' ' + res_ls[max_index] + '/' + input_type_dicts[arr_index][res_ls[max_index]] + ' '
            i += max_len
            break

        arr_index += 1


    result += comd[i]
    i += 1

print(result)

**/