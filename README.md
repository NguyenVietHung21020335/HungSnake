*Snake
**Game Snake cổ điển
________________________________________


*Hướng dẫn cài đặt
Cần thêm một số bước cài đặt thư viện để chạy chương trình bao gồm :MinGW-W64, SDL2 ,SDL2_image
Link tải chương trình dịch : https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z/download
Link tải thư viện:
SDL2 : https://www.libsdl.org/release/SDL2-devel-2.0.20-mingw.tar.gz
SDL2_image : https://www.libsdl.org/projects/SDL_image/ (Chọn phiên bản phù hợp với máy)

Bước Setting:
Đầu tiên mở "Environment Valiables" bằng cách tìm kiếm "Path"
Sau đó chọn "Path" rồi add các đường dẫn đến file "bin" trong các file vừa tải . Vd: C:\software\sdl_image\x86_64-w64-mingw32\bin
Với CodeBlocks:
Vào Setting/Compile/Linker settings rồi dán "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image " vào phần Other linker options

Sau đó vào "Search directories" :

Chọn "Compiler" :Add các đường dẫn đến "SDL2" . Vd: C:\software\SDL2-2.2.20\x86_64-w64-mingw32\include\SDL2 C:\software\sdl_image\x86_64-w64-mingw32\include\SDL2
Chọn "Linker" : Add các đường dẫn đến "lib" (Tương tự như cách add như trên) *Xong thì bấm OK là hoàn thành xong bước set up đầu tiên
Bấm chuột phải vào project rồi chọn "Build options" rồi làm các bước y như trên


•	Chạy file project HungSnake.cbp



*Mô tả
Lấy ý tưởng từ game Snake, sử dụng 4 phím [UP], [DOWN], [LEFT], [RIGHT] để di chuyển con rắn ăn thức ăn trên màn.
Game được viết bằng ngôn ngữ C++ và sử dụng thư viện SDL2, SDL2_image.
LUẬT CHƠI:
•	Nhiệm vụ của người chơi là nhập vai vào HungSnake - Một chú rắn nhỏ để đi săn tìm thức ăn để giúp chú rắn lớn lên. 
o	Nhấn UP  để di chuyển rắn đi lên
o	Nhấn DOWN để di chuyển rắn đi xuống
o	Nhấn LEFT để di chuyển rắn đi sang trái
o	Nhấn RIGHT  để di chuyển rắn đi sang phải



*Các chức năng
•	Màn hình khởi động của game với board 900x600 cho phép người chơi chọn bắt đầu hay thoát bằng click chuột.
•	Màn hình chơi chính với board 900x600 để di chuyển rắn đi săn mồi.
•	Màn hình sau khi thua với board 900x600 cho phép người chơi chơi lại hay thoát bằng click chuột.
Video: https://www.youtube.com/watch?v=eZ7gE-3-8as



*Kỹ thuật đã sử dụng
•	Mảng
•	Con trỏ/ Giải phóng bộ nhớ
•	Class/Struct
•	Đồ hoạ
•	Bắt sự kiện bàn phím, chuột
•	Sinh số ngẫu nhiên 
•	Các thư viện chuẩn của C++
•	Tách file và quản lý file trong project



*Kết luận
•	Hướng phát triển: Em sẽ cải tiến thêm các tuỳ chọn như :
o	Hướng dẫn chơi
o	Các độ khó
o	Thêm map
o	Thêm nhân vật
o	Thêm âm thanh
o	Hiển thị điểm số,  bảng xếp hạng có tên người chơi 
o	Phân loại kết quả của người chơi.
trong tương lai và cũng nghiên cứu cách khắc phục sự thiếu xót của SDL như Scrolling ảnh, SDL_Delay chỉ nhận được số mili giây nguyên .
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
