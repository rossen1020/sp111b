# linux筆記
**111010516 資工二 賴映羽**
***
## 筆記:
```
"~" 所代表的是加目錄 
	如果是在root 目錄會是: /home/root
	如果是在user 目錄會是: /home/user
```
```
" sudo " 在想執行的階段,可 臨時切換為超級使用者, 當執行完畢再次回復成一般使用者
" su " 成為超級使用者
超級使用者的提示符號為" # "
一般使用者的提示符號為" $ "
```
```
管道 pipe " | " 
"chmod +x 檔案名 " 賦予可執行的權力
"dmesg | more "把系統的訊息全列出來
" man 指令名 " 條列指令名的功能和用法
">"導向
" usr "放第三方可執行檔的地方
" which "可知道執行檔位置
```
```
enp0s3 :代表是NAT網路卡
enp0s8 :代表是Host-only網路卡

" wget 網域 "代表運用wget去抓取網頁地址, 
再輸入" echo $? "能確認網域是否存在, 0為存在, 其餘值為錯誤
```
```
快照的功能可開機超做也可關機操作, 主要是能回復到曾經的操作
```
```
在linux中大小寫是有區分的, 執行檔的副檔名(exe, txt, asp)沒有差別, 
只是參考用, 真正要看的是它的內容或屬性和權限, 即使是txt檔也可以被用來當執行檔
```
```
pstree 是 linux 第一個執行的命令
```
```
init /systemd 為linux 第一個程式, 
他會啟動已配置(enable)的模式, 沒配置(disable)的模式就不會
```
```
grub 是linux的開機管理系統, 可分開進入不同系統
```
```
"find" 可尋找檔案, "-name"可指定尋找的檔案名, " -i "可不分大小寫
```
### linux 分割區有兩個:
```
1.根目錄 " / ", 給整個系統使用 
2. swap : linux 的虛擬記憶體, 利用硬碟空間擴充
```
### 檔案時間有三個:
```
access: 讀取時間
modify:修改時間
change:
```
### linux常用掛載檔案格式:
```
ext2 ext3 ext4 xfs 
```
### 權限
```
r :可讀取
w :可寫,新增,修改,刪除
x :可執行
– :不允許該權限
```
***
## 指令集:
```
" hostnamectl set-hostname 新名字 " 更改主機名稱
" cd  -" 代表回到上個路徑
" clear " 代表清除頁面指令
" reboot " 使電腦重開機
" kill -9  [ --pid-- ] " 強制刪除停止背景安裝的軟體(建議不要常做)
```
```
" rm " 刪除某項檔案
" rm -rf "刪除全部檔案 rm:remove ,-r:recursive ,-f:force
```
```
" ctrl+c "中斷程式執行
" ctrl+z "丟到背景執行
" halt -p " 關機
```
```
ctrl+a: 會跳到指令行最前面
ctrl+e: 會跳到指令行最後面
alt+d:在最前面時,會刪掉後面的所有字
```
```
" yum install " 下載指令, 後面加上" -y "代表一律許可下載
" yum remove software_package " 移除軟體
```
```
" netstat " : 查看ip狀態   
-t : TCP    -u : UDP    -l : LISTEN    p : prosses   n: 不解析
" |  grep  戶號  " :查看所篩選的戶號
0.0.0.0代表任一介面的ip
```
```
ls -a ##檢視隱藏檔案 .cache(隱藏檔案)
ls -l -h -a = ls -lha = ls -ahl
```
```
"echo 1 > /proc/sys/net/ipv4/ip_forward "開熱點
"echo 1 > /proc/sys/net/ipv4/ip_forward "關熱點
```


### 執行 a.sh
```
"echo hi" > a.sh ##輸入echo hi 到a.sh
chmod +x a.sh ##change mod +x(可執行)
./a.sh ##執行結果 hi(加./增加安全性)
cat a.sh ##執行結果 echo hi
file a.sh ##可察看檔案屬性
```

### 導向資料
```
echo "2" 1>a.txt == echo "2" >a.txt
ls /aaa ##會報錯
ls /aaa 2>error.txt ##把報錯寫入error.txt(2不能省略)
ls /tmp/aaa 1>a.txt 2>&1 ##1可省略
ls /tmp/aaa >/dev/null 2>&1 ##把內容丟掉
```
### df指令

```
df -h ##知道磁碟檔案大小
" du " 為文件目錄
" df " 為磁碟分割區
" du -h" 可查看每個文件所佔的大小, 最後一行還可以看總共大小, 指令後面可加上指定的
文件目錄, 加上"--max-depth [數字] "可指定要查看的深度
```
### 使用者

```
新增使用者:
adduser tom 
修改使用者密碼:
echo "123456" | passwd --stdin tom 
```

### grep


```
# a 開頭
ls | grep "^a"
# b 結尾
ls | grep "b$"
# a 或 b 開頭
ls | grep "^[ab]"
# a 或 b 結尾
ls | grep "[ab]$"
```

各種出現次數的指定：

```
# S 開頭，接著 o 出現零次以上
cat /etc/passwd | grep "^So*"
# r 開頭，接著 o 出現零次或一次
cat /etc/passwd | egrep "^So?"
# r 開頭，接著 o 出現一次以上
cat /etc/passwd | egrep "^So+"
```

多種字眼的組合，也很常用：

```
# 含有 ab 或 cd
cat /etc/passwd | egrep "root|user|tom"
# 含有 ab 或 cd（另一種寫法，作用相同）
cat /etc/passwd | grep -E "root|user|tom" ##使用擴充型的正則表達式(同egrep)
```



如果只想要精準篩選出 net 這個單字，可以這樣寫：

```
# net 這個單字
grep -w net
```

### systemctl

firewalld:
```
檢查服務狀態:
systemctl status firewalld
設定開機自動啟動服務 :
systemctl enable firewalld 
關閉服務:
systemctl disable firewalld 
```
```
將 iptables 服務永久關閉:
systemctl mask iptables
```
設網站:
```
yum install httpd
systemctl start httpd
systemctl status httpd
```

### 符號

```
#	註解
;	不管前面的指令成功與否後面的指令都會繼續執行
&&	前面的指令如果失敗後面的就會拒絕執行
$?	可以看下的只領有沒有成功(有=0,沒有=非0值)
$#	輸入參數的個數
$_	$0可知道命令本身
```

### vim

命令模式
```
w: write  
q:quit   
wq:write and quit   
q!:quit and give up modified things
```
