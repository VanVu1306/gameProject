# **Tomb Runner**
## **Thông tin sinh viên**

- Họ và tên: Vũ Nhật Tường Vân
- MSSV: 23021747

## **Giới thiệu**

Tomb Runner là một tựa game phiêu lưu sống sót trong mê cung hầm mộ. Trong quá trình chơi, người chơi tìm cách vượt qua các chướng ngại vật khác nhau kết hợp ăn nhiều xu nhất có thể để có cơ hội được tăng level.

![menu](/preview/menu.png)
![normalMode](/preview/normalMode.png)
![lavaMode](/preview/lavaMode.png)

## **Mô tả game**
### *Cách chơi*
- Sử dụng 4 nút di chuyển `↑`, `↓`, `←`, `→` để đi lại trong map
- Né các chướng ngại vật và thu thập xu 
- Người chơi thua khi va chạm với chướng ngại vật
- Nếu thu thập đủ số xu yêu cầu của mỗi level, người chơi sẽ có cơ hội hồi sinh tại level đó và bị trừ số xu tương ứng, nếu không sẽ phải chơi lại từ đầu và mất toàn bộ xu

### *Chướng ngại vật và bổ trợ*
- Normal Mode: Các chướng ngại vật như dơi (bats), phi tiêu (darts), cá nóc (puffer), gai (spike), và tính năng bổ trợ dịch chuyển (teleports). Mỗi chướng ngại vật này có 1 đặc điểm chuyển động và biến đổi khác nhau.
- Lava Mode: Dung nham (lava) dâng lên từ đáy map.
- Các chướng ngại vật đều dẫn đến thua cuộc khi va chạm.

### *Cấu trúc và chức năng trong game*
- Menu: gồm 2 nút chọn game mode (Normal Mode và Lava Mode) và nút exit (thoát trò chơi từ menu)
- Normal Mode: hiện nay có 12 levels khác nhau
- Lava Mode: hiện nay có 4 levels khác nhau
- Màn hình giới thiệu chướng ngại vật
- Quit: gồm 2 nút Yes và No để người chơi quyết định thoát trò chơi từ trong game
- Màn hình thắng cuộc
- Màn hình thua cuộc
- Màn hình cho phép hồi sinh
- Hiển thị số xu đã thu thập

## **Kỹ thuật lập trình đã sử dụng**
- Các thư viện SDL2 (SDL2_image, SDL2_mixer, SDL2_ttf)
- Xử lý Mouse Event, Key Event
- Scrolling View
- Sử dụng hoạt ảnh (Sprites)
- Sound effects và Music
- Struct và Class
- Vòng lặp
- Mảng và vector
- Con trỏ
- Xử lý va chạm (giữa các chướng ngại vật với map, giữa người chơi với map và giữa chướng ngại vật với người chơi)

## **Ngưỡng điểm tự đánh giá và lý do**

### *Ngưỡng điểm mong muốn: 7,5 đến 8*

### *Lý do:* 
Game có code tự viết, sử dụng thuật toán đơn giản, bên cạnh đó có phát triển về đồ họa, âm thanh, di chuyển, hoạt ảnh,...
