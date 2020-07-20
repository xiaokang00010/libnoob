# ElangageFramework
一个有用的函数库，努力做到让C++开发像易语言一样简单

<div class="d-flex flex-column flex-md-row">
    <div class="p-3 col-md-6">
      <svg height="32" class="octicon octicon-law text-gray-dark float-left mr-2" viewBox="0 0 24 24" version="1.1" width="32" aria-hidden="true"><path fill-rule="evenodd" d="M12.75 2.75a.75.75 0 00-1.5 0V4.5H9.276a1.75 1.75 0 00-.985.303L6.596 5.957A.25.25 0 016.455 6H2.353a.75.75 0 100 1.5H3.93L.563 15.18a.762.762 0 00.21.88c.08.064.161.125.309.221.186.121.452.278.792.433.68.311 1.662.62 2.876.62a6.919 6.919 0 002.876-.62c.34-.155.606-.312.792-.433.15-.097.23-.158.31-.223a.75.75 0 00.209-.878L5.569 7.5h.886c.351 0 .694-.106.984-.303l1.696-1.154A.25.25 0 019.275 6h1.975v14.5H6.763a.75.75 0 000 1.5h10.474a.75.75 0 000-1.5H12.75V6h1.974c.05 0 .1.015.14.043l1.697 1.154c.29.197.633.303.984.303h.886l-3.368 7.68a.75.75 0 00.23.896c.012.009 0 0 .002 0a3.154 3.154 0 00.31.206c.185.112.45.256.79.4a7.343 7.343 0 002.855.568 7.343 7.343 0 002.856-.569c.338-.143.604-.287.79-.399a3.5 3.5 0 00.31-.206.75.75 0 00.23-.896L20.07 7.5h1.578a.75.75 0 000-1.5h-4.102a.25.25 0 01-.14-.043l-1.697-1.154a1.75 1.75 0 00-.984-.303H12.75V2.75zM2.193 15.198a5.418 5.418 0 002.557.635 5.418 5.418 0 002.557-.635L4.75 9.368l-2.557 5.83zm14.51-.024c.082.04.174.083.275.126.53.223 1.305.45 2.272.45a5.846 5.846 0 002.547-.576L19.25 9.367l-2.547 5.807z"></path></svg>
      <p class="text-small text-gray mb-0 lh-condensed-ultra">
        xiaokang00010/ElangageFramework is licensed under the
      </p>
      <h3 class="mt-0 mb-2 h4">GNU General Public License v3.0</h3>
      <p class="mb-0 text-gray text-small pr-2">Permissions of this strong copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights.</p>
    </div>



## namespace Text
### 解释
关于文本的函数库

string getSubText(string MasterText, int startPoint, int length)

string getLeftText(string MasterText, int length)

string getRightText(string MasterText, int length)

int isInString(string MasterText, string subtext)

int getStrCount(string MasterText, string subtext)

string StringTransform(string str, int start = 0, int end = 0, int TransMode = TRANSMODE_ALL_COVER)

string ToString(string s)

vector<string> split(string f,const string t) **该函数在之前存在旧版本，新版已采用awathefox的设计
  
string deleteStr(string MasterText, string s)

## namespace EasyFiles
### 解释
让读写文件不需要繁琐的文件流

string ReadFile(string FileName)

string WriteFile(string FileName,string Output)

## namespace dataobj
### 解释
一些常用的数据类型

### 包含

etime

FrameworkApiVer

Rectangle

timer

## Dictory 一个类似于python的词典

## class EConfig
### 解释
EConfig(\*.econf) 配置文件读写

*EConfig(string filename,string linesep = "\n")* 构造函数

string readString(string key)

void writeString(string key,string value)

*void commitChanges()* 将更改保存至EConfig文件

Powered by player0010 and awathefox

/*--------------------------------------------------------*/<br>
/*           ElangFramework! Public Preview               */<br>
/* 本框架仅为公开预览版, 里面所展示的所有特性不代表正式版会继承该特性 */<br>
/*                                                        */ <br>
/*                 遵循GPL开源协议开发                       */<br>
/*             Copyright 2020 Player0010                  */<br>
/*           在程序中包含ElangInclude以使用此库               */<br>
/*              Change Log: www.00010.ml                  */<br>
/*--------------------------------------------------------*/<br>
