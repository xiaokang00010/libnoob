/*--------------------------------------------------------*/
/*           ElangFramework! Public Preview               */
/* 本框架仅为公开预览版, 里面所展示的所有特性不代表正式版会继承该特性 */
/*                                                        */ 
/*                 遵循GPL开源协议开发                       */
/*             Copyright 2020 Player0010                  */
/*           在程序中包含ElangInclude以使用此库               */
/*              Change Log: www.00010.ml                  */
/*--------------------------------------------------------*/
#include <iostream>
#include <ios>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <vector>

#define EASYFILE_BIN             0
#define EASYFILE_TEXT            1
#define TRANSMODE_ALL_COVER      1
#define TRANSMODE_ONLY_BIG       2
#define TRANSMODE_ONLY_SMALL     3

using namespace std;

// 枚举常量定义开始
enum INIFILE_STAT{CLOSE,OPEN};

// 枚举常量定义结束

namespace Text{
	string getSubText(string MasterText, int startPoint, int length){
	    return MasterText.substr(startPoint,length);
	}

	string getLeftText(string MasterText, int length){
		return MasterText.substr(0,length);
	}

	string getRightText(string MasterText, int length){
		string tempText;
		tempText=getSubText(MasterText, MasterText.length() - length, MasterText.length());
		return tempText;
	}	

	int isInString(string MasterText, string subtext){
		string tempText;
		for(int i = 0;i < MasterText.length();i++){
			tempText = Text::getSubText(MasterText,i,i+subtext.length());
			if(tempText==subtext){
				return i;
			}
		}
		return 0;
	}

	int getStrCount(string MasterText, string subtext){
		string tempText;
		int cnt;
		for(int i = 0;i < MasterText.length();i++){
			tempText = Text::getSubText(MasterText,i,i+subtext.length());
			if(tempText==subtext){
				cnt++;
			}
		}
		return cnt;
	}

	string StringTransform(string str, int start = 0, int end = 0, int TransMode = TRANSMODE_ALL_COVER){
        string s = str;
		if(TransMode = TRANSMODE_ALL_COVER){
			for(int i = start;i < end;i++){
				if(s[i] >= 65 && s[i] <= 90){
					s[i] += 32;
				}else if(s[i] >= 97 && s[i] <= 122){
					s[i] -= 32;
				}
			}
		}else if(TransMode = TRANSMODE_ONLY_SMALL){
			for(int i = start;i < end;i++){
				if(s[i] >= 65 && s[i] <= 90){
					s[i] += 32;
				}
			}
		}else if(TransMode = TRANSMODE_ONLY_BIG){
			for(int i = start;i < end;i++){
				if(s[i] >= 97 && s[i] <= 122){
					s[i] -= 32;
				}
			}
		}

		return s;
	}

	string ToString(string s){
		return s;
	}
	
	vector<string> split(string f,const string t){
	    vector<string> c;
	    while(f!=""){
	        c.push_back(f.substr(0,f.find(t)==string::npos?f.length():f.find(t)));
	        f.erase(0,f.find(t)==string::npos?f.length():f.find(t)+1);
	    }
	    return c;
	} // change by awathefox
	
	string deleteStr(string MasterText, string s){
		const string str = s;
		string ret;
		vector<string> strVec = split(MasterText,str);
		for(int i = 0;i < strVec.size();i++){
			ret+=strVec[i];
		}
		return ret;
	}
    vector<string> comSplit(string str,const char splitCh){
        string command = str;
        //cout << command;
        vector<string> ret;
        string buf;
        for(size_t i = 0;i < command.length();i++){
            bool flag;
    
            if(command[i] == '"'){
                flag = !flag;
            }
    
            // 放入缓存
            if(command[i] != splitCh || flag == true || i == command.length() - 1){
                char n = command[i];
                buf = buf + n;
            }
    
            // 放入数组
            if((command[i] == splitCh && flag != true)){
                ret.push_back(buf);
                buf = "";
            }else if(i + 1 == command.length()){
                ret.push_back(buf);
                buf = "";
            }
        }
        return ret;
    }
}

namespace EasyFiles{
	string ReadFile(string FileName){
		string ret;
		string temp;
		fstream f2;
    	f2.open(FileName.data());
		if(!f2.is_open())return "";
		while(!f2.eof()){
			//f2 >> ret;
			getline(f2,temp);
			ret+=temp+"\n";//加换行
		}
		ret.erase(ret.length()-1,1);
		f2.close();
		return ret;
	}

	string WriteFile(string FileName,string Output){
		fstream f1;
    	f1.open(FileName.data(),ios::in|ios::out);
		f1 << Output;
		f1.close();
		return Output;
	}
}

namespace dataobj{
	class etime{
	public:
		int nyear = 1970;
		int nmon = 1;
		int nday = 1;
		int nhour = 0;
		int nmin = 0;
		int nsec = 1;
        string year = "1970";
        string months = "1";
        string date = "1";
        string hour = "0";
        string minture = "0";
        string second = "0";
        string formatOutput(string format){
            string ret;
            if(format == "default_OnlyDate"){
                ret = year + Text::ToString("-") + months + Text::ToString("-") + date;
            }else if(format == "default_OnlyTime"){
            	ret = hour + Text::ToString("-") + minture + Text::ToString("-") + second;
			}else if(format == "default_All"){
				ret = year + Text::ToString("-") + months + Text::ToString("-") + date + Text::ToString("-") + hour + Text::ToString("-") + minture + Text::ToString("-") + second;
			}
			return ret;
        }
        
        void ToEtime(time_t finTime = time(0)){
        	time(&finTime);
			tm* t_tm = localtime(&finTime);	
				
			nyear = t_tm->tm_year+1900;
			nmon = t_tm->tm_mon+1;
			nday = t_tm->tm_mday;
			nhour = t_tm->tm_hour;
			nmin = t_tm->tm_min;
			nsec = t_tm->tm_sec;
			
			year = to_string(nyear);
    	    months = to_string(nmon);
        	date = to_string(nday);
        	hour = to_string(nhour);
        	minture = to_string(nmin);
        	second = to_string(nsec);
		}
		
    };
    etime getTime(int year_ = 1970 , int months_ = 1 , int date_ = 1 , int hour_ = 0 , int minture_ = 0 , int second_ = 1){
        etime ret;
        ret.year = year_;
        ret.months = months_;
        ret.date = date_;
        ret.hour = hour_;
        ret.minture = minture_;
        ret.second = second_;
        return ret;
    }

    struct FrameworkApiVer{
        const string ApiName = "ElangageFramework";
        const string ApiText = "[Elangage Framework] 0.1 rel.2\nTHIS IS A PREVIEW VERSION, NOT RELEASES!";
        const int apiCode = 10;
        const bool IsSupportElangInclude = true;
        const etime ComplieTime = getTime(2020,7,1,20,30,20);
    };
    
    class Rectangle{
    	public:
	    	int x = 0;
	    	int y = 0;
	    	
	    	int getArea(){
	    		return x*y;
			}
			
			int getPeri(){
				return (x+y) * 2;
			}
	};
	
	class timer{
		public:
			void startTimer(){
				updateTime();
				stat = 1; // 更新计时器状态
				startTime = nowtime;
			}
			
			etime endTimer(){
				if(stat != 1){
					return getTime();
				}
				etime ret;
				
				updateTime();
				endTime = nowtime;
				
				time_t finTime = endTime - nowtime;  //计算当前时间
				time(&finTime);
				tm* t_tm = localtime(&finTime);
				
				
				int year = t_tm->tm_year+1900;
				int mon = t_tm->tm_mon+1;
				int day = t_tm->tm_mday;
				int hour = t_tm->tm_hour;
				int min = t_tm->tm_min;
				int sec = t_tm->tm_sec;
				
				ret = getTime(year , mon , day , hour , min , sec);
				
				return ret;
			}
			
		private:
			time_t nowtime = 0;
			
			time_t startTime;
			time_t endTime;
			
			int stat;
			void updateTime(){
				nowtime = time(0);  // 更新当前时间
			}
	};
}

namespace linux_os{
	string getRealpath(string flinuxpath = "."){ 
		// 也可以当作获得当前目录使用
		// Sample: getRealpath()
		// Return: <当前目录实际路径>
    	char buf[256];
    	string ret;
    	if(realpath(flinuxpath.data(),buf)){
        	ret = buf;
	        return ret;
    	}else{
        	perror("LibraryError: Unknown Linux Path\n");
        	return Text::ToString("");
    	}
	}

	string getHostName(){
		char hostname[1024];
		gethostname(hostname,1024);
		string ret = hostname;
		return ret;
	}
}

template <typename T,typename T2> class Dictory{
	private:
		vector<T> key;
		vector<T2> value;
	public:
		string id;

		Dictory(string id_ = "nul"){
			id = id_;
		}

		bool isInDictory(T k){
			typename vector<T>::iterator result = find(key.begin(), key.end(), k);
			int n = distance(key.begin(),result);
			return (result == key.end()) ? false : true;
		}

		int getSize(){
			return key.size();
		}

		int getIndex(T k){
			typename vector<T>::iterator result = find(key.begin(), key.end(), k);
			int n = distance(key.begin(),result);

			return n;
		}

		int push_back(T n_key,T2 n_value){
			// 函数说明: 加入新的成员,返回词典的大小
			key.push_back(n_key);
			value.push_back(n_value);
			return key.size();
		}

		T2 getValue(T k){
			int pos = getIndex(k);
			return value[pos];
		}
		
		int setValue(T k,T2 n_v){
			int pos = getIndex(k);
			value[pos] = n_v;
			return getSize();
		}

		int deleteKey(T k){
			typename vector<T>::iterator pos = find(key.begin(),key.end(),k);
			int index = getIndex(k);
			typename vector<T2>::iterator pos2 = find(value.begin(),value.end(),value[index]);
			key.erase(pos);
			value.erase(pos2);
			return getSize();            // 返回数组当前大小
		}

		void clear(){
			key.clear();
			value.clear();
		}
};

class EConfig{
	private:
		vector<string> cuttedStr;
		Dictory<string,string> dic;
		string sep      = "\n";
		string fileName = "";
	public:
		EConfig(string filename,string linesep = "\n"){
			cuttedStr = Text::split(EasyFiles::ReadFile(filename),linesep);
			
			// 读入字典
			for(int i = 0;i < cuttedStr.size();i++){
				if(cuttedStr[i][0] == '#') continue;
				// 噩梦部分，不知道要在这里卡多久...奇迹！居然那么短的时间就搞完了！
				vector<string> tmp = Text::split(cuttedStr[i],"=");
				if(tmp.size() <= 1){
					cout << "框架异常: 此EConfig配置文件不合法.\nThrow error at " << i << " , exit...\n";
					exit(-1);
				}
				string left  = tmp[0];
				string right = Text::getRightText(cuttedStr[i], cuttedStr[i].length() - left.size() - 1);
				dic.push_back(left,right);
				fileName = filename;
				sep = linesep;
			}
		}

		int getConfigContentLength(){
			return dic.getSize();
		}

		string readString(string key){
			return dic.getValue(key);
		}

		void writeString(string key,string value){
			for(int i = 0;i < cuttedStr.size();i++){
				if(cuttedStr[i][0] == '#') continue;
				vector<string> tmp = Text::split(cuttedStr[i],"=");
				string left  = tmp[0];
				string right = Text::getRightText(cuttedStr[i], cuttedStr[i].length() - left.size() - 1);
				if(left == key){
					cuttedStr[i] = left + Text::ToString("=") + value;
					return;
				}
			}
			cuttedStr.push_back(key + Text::ToString("=") + value);
		}

		void commitChanges(){
			string ret;
			for(int i = 0;i < cuttedStr.size();i++){
				ret+=cuttedStr[i]+sep;
			}
			ret = Text::getLeftText(ret,ret.length() - sep.length());
			EasyFiles::WriteFile(fileName,ret);
		}
}; 