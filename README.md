Báo cáo bài tập lớn cuối kì 
________________________________________

*Snake 
  *Game Snake cổ điển
________________________________________


I. Hướng dẫn cài đặt:
1.	Đối với hệ thống 64 bit:
+ Tải Project “Hung’s snake” từ github https://github.com/NguyenVietHung21020335/HungSnake:
- Nhấn vào “Code” màu xanh, nhấp chọn “Download ZIP” để tải project về. 
-	Giải nén tệp vừa tải.


        + Cài đặt:
            - Cài đặt CodeBlock: 
                o	Nhấn vào đường dẫn này và cài đặt  trình biên dịch Codeblocks: https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z/download
            - Cài đặt thư viện: 
                o	SDL : https://www.libsdl.org/release/SDL2-devel-2.0.20-mingw.tar.gz
                o	SDL2_image : https://www.libsdl.org/projects/SDL_image/ (Chọn phiên bản phù hợp với máy và dành cho nhà phát triển). Ví dụ: SDL2_image-devel-2.0.5-mingw.tar.gz
                o	SDL2_mixer : https://www.libsdl.org/projects/SDL_mixer/ (Chọn phiên bản phù hợp với máy và dành cho nhà phát triển). Ví dụ:   SDL2_mixer-devel-2.0.4-mingw.tar.gz
                o	SDL2_ttf : https://www.libsdl.org/projects/SDL_ttf/release/ (Chọn phiên bản phù hợp với máy và dành cho nhà phát triển). Ưu tiên chọn bản mới nhất, ví dụ:
SDL2_ttf-devel-2.0.18-mingw.tar.gz


        +	Thiết lập:
            - Giải nén các tệp thư viện, tìm mục “bin” trong các folder thư viện, copy đường dẫn.
            - Mở "Environment Valiables", nháy đúp chuột vào mục “Path”, ấn “New” và thêm đường dẫn vào các folder “bin” vào. Ví dụ: C:\Users\NGUYEN VIET HUNG\Desktop\DoHoa\SDL2-2.0.20\x86_64-w64-mingw32\bin
        +	Trong Codeblocks:
            - Vào Setting/Compile/Linker settings rồi dán "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf" vào phần Other linker options
            - Vào Setting/Compile/Search directories/Complier. Nhấn add và thêm các thư mục “SDL2”.  
            - Vào Setting/Compile/Search directories/Linker. Nhấn add và thêm các thư mục “lib”.  
            - Nhấn OK để lưu.
            - Vào folder chứa Project đã giải nén mở file HungSnake.cbp để chạy project.
            - Nhấn chuột phải vào Project chọn “Build option” và tương tự trong setting của Codeblocks. 
        +	Với VsCode:
            - Làm theo hướng dẫn này : https://pie-cheque-188.notion.site/C-i-t-h-a-C-Windows-ef0a99a8dcae4dae86a39dc1cbc35980 .
            - Cài đặt các thư viện như trong codeBlocks (cài tương tự như cài SDL trong link hướng dẫn ở trên)
            - Trong "Makefile": all: g++ -Isrc/include -Lsrc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
    2.	Đối với hệ thống 64 bit: 
        +	Tương tự như cách cài phiên bản x64(64bit)


II. Mô tả chung
(1)	Lấy ý tưởng từ game Snake, sử dụng 4 phím [UP], [DOWN], [LEFT], [RIGHT] để di chuyển con rắn ăn thức ăn trên màn.
(2)	Game được viết bằng ngôn ngữ C++ và sử dụng thư viện SDL2, SDL2_image, SDL_mixer, SDL_ttf.
(3)	Luật chơi:
•	Nhiệm vụ của người chơi là nhập vai vào HungSnake - Một chú rắn nhỏ để đi săn tìm thức ăn để giúp chú rắn lớn lên.
o	Nhấn UP  để di chuyển rắn đi lên
o	Nhấn DOWN để di chuyển rắn đi xuống
o	Nhấn LEFT để di chuyển rắn đi sang trái
o	Nhấn RIGHT  để di chuyển rắn đi sang phải
•	Rắn ăn được càng nhiều thì điểm càng cao.
•	Trò chơi kết thúc khi cắn phải thân hay tường.

III. Các chức năng 

•	Màn hình khởi động  Menu của game   với board 900x600 cho phép người chơi chọn bắt đầu chơi “Play” hay xem bảng điểm cao “Highscore” bằng click chuột.
•	Nếu chọn click “Highscore” thì bảng điểm cao được hiện ra, nếu bấm “Play” thì bảng tiếp theo hiện ra cho phép người chơi click chọn hình rắn sẽ chơi.
•	Chọn rắn xong sẽ xuất hiện bảng tiếp theo cho phép người chơi chọn độ khó của trò chơi bằng click.
•	Sau khi chọn xong màn hình game chính sẽ xuất hiện để bắt đầu chơi.
•	Khi thua, bảng điểm sẽ được hiển thị và điểm sẽ được lưu vào Highscore. 
•	Màn hình sau khi thua được hiện với lời kết khác nhau tùy theo số điểm mà người chơi đạt được. Tại màn hình này người chơi có thể chọn trở về Menu “Restart” hoặc thoát game “Exit” bằng click.
•	Video: 
IV. Kỹ thuật lập trình đã sử dụng
•	Mảng
•	Con trỏ/ Giải phóng bộ nhớ
•	Class/ Struct
•	Các thư viện SDL, SDL_image, SDL_ttf, SDL_mixer
•	Bắt sự kiện bàn phím, chuột.
•	Sinh số ngẫu nhiên
•	Các thư viện chuẩn của C++
•	Tách file và quản lý file trong project

V. Kết luận 
•	Hướng phát triển: Em sẽ cải tiến thêm các tuỳ chọn như :
o	Có bảng hướng dẫn chơi
o	Thêm nhiều map
o	Thêm hiệu ứng âm thanh mỗi khi đạt mốc điểm nhất định
o	Cho người chơi nhập tên
o	Bảng xếp hạng có tên người chơi
o	Thêm nhiều loại quả với các hiệu ứng và chức năng khác nhau.
o	Khắc phục sự thiếu xót của SDL như Scrolling ảnh, SDL_Delay chỉ nhận được số mili giây nguyên .

•	Qua thời gian làm game, em đã rút ra được cho bản thân rất nhiều bài học như:
o	Hiện nay thông tin về lập trình ở mức độ hiện tại trên các phương tiện thông tin, và mình cần phải tiếp cận được những nguồn kiến thức đó bằng cách nâng cao kĩ năng tìm kiếm thông tin, đặc biệt là các tài liệu tiếng Anh.
o	Giúp em hiểu rõ và thuần thục hơn trong việc sử dụng các thư viện nhưu SDL hay SDL_image
o	Nếu như trước đây chỉ làm những bài tập nhỏ chỉ vài chục dòng code thì mình có thể sửa lỗi khá dễ dàng nhưng đến với những project bắt đầu phức tạp như lần này thì mình cần phải có sự sắp xếp mọi thứ gọn gàng dễ hiểu. Cá nhân em trong quá trình làm đã mất 12 tiếng liên tục làm việc chỉ để fix một cái lỗi siêu ngớ ngẩn và nguyên nhân là việc mình không sắp xếp thông tin một cách hợp lí. Vì vậy mình cần tạo sắp xếp một cách hợp lí trong lập trình từ cả những project nhỏ để có thể tạo thói quen tốt.
o	Ngôn ngữ trong lập trình không quá quan trọng, quan trọng là cách mình tư duy, cần hiểu vấn đề cặn kẽ và sử dụng các công cụ một cách hợp lý.
*CREDIT
Em xin gửi lời cảm ơn tới
•	Thầy Nguyễn Việt Anh
•	Thầy Trần Quốc Long
•	Thầy Nguyễn Hoàng Minh Công
Đã giúp em có thể làm được dự án này.
