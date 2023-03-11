#include <_types/_uint32_t.h>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "ipv4.h"

using std::string, std::vector, std::pair;
// using std::make_pair, std::stoi, std::cout, std::endl;
using namespace std::literals;

// auto split_by_space_dot(string s) -> vector<string> {
// 	vector<std::uint32_t> ret{};
// 	string cache; 
// 	for(auto& c: s) {
// 		if (c == ' ' || c == '.') {
// 			if ( cache.size() > 0 )
// 				ret.push_back(stoi(cache));
// 			cache.clear();
// 		}
// 		else if (c >= '0' && c <= '9')
// 			cache += c;
//         else
// 	}
// 	if (cache.size() != 0)
// 		ret.push_back(stoi(cache));
// 	return ret;
// }

auto f(string s) -> pair<uint32_t, uint32_t> {
    vector<std::uint32_t> ret{ };
    uint32_t seg = 0;
    uint32_t seg_len = 0;
	for(auto& c: s) {
		if (c == ' ' || c == '.') {
			if ( seg_len > 0 ) {
                if (seg < 256)
    				ret.push_back(seg);
                else 
                    return {0u , ErrCode::overflow_u8};
            }
            seg = 0;
			seg_len = 0;
		} else if (c >= '0' && c <= '9') {
            uint32_t tmp = seg;
            seg = tmp * 10;
            seg += (c - '0');
            if(seg < tmp)
                return {0u, ErrCode::overflow_u32};

            seg_len ++;
        } else [[unlikely]] { // match other char
            return {0u, ErrCode::nan};
        }
	}
	if (seg_len > 0) 
		ret.push_back(seg);
    // for(auto i: ret)
    //     cout << i << " ";
    // cout << endl;
	if(ret.size() != 4)
		return {0u, ErrCode::err};
	uint32_t ans = 0;
    for(auto i=0; i < ret.size(); i++) {
        ans *= 256;
        ans += ret[i];
    }

	return {ans, ErrCode::ok};
}