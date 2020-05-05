<?php

/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 05.05.2020
*/

//First we have to set the output of the page.
//Here we set it as image. Because we are going to show an image directly
header('content-type: image/jpeg');

//Then we set the image and watermark image.
$source_image = 'image.jpg';
//Important thing is we need to create watermark image as png image.
//Else the transparent ares will be white colored in our watermark image area.
//And also we need to use a png image to show transparency.
$my_watermark = imagecreatefrompng('watermark.png');

//Then we will get the width and height of the watermark image.
//We will use these dimensions to locate it fit position.
$watermark_width = imagesx($my_watermark);
$watermark_height = imagesy($my_watermark);

//So now we are going to create our image component from the source image.
$image = imagecreatefromjpeg($source_image);
//and we get its dimensions
$image_size = getimagesize($source_image);

//Then we specify the position of the watermark.
//We will locate it right under corner of the image with 20px margin from edges.
$wm_x = $image_size[0] - $watermark_width - 20;
$wm_y = $image_size[1] - $watermark_height - 20;

//Then we are copying the watermark image on created image component with configured locations and dimensions.
imagecopy($image, $my_watermark, $wm_x, $wm_y, 0, 0, $watermark_width, $watermark_height);

//Lastly show the image on the screen. Do not forget to set header as image of the page.
imagejpeg($image);

//And destroy variables to prevent using memory.
imagedestroy($image);
imagedestroy($my_watermark);


?>


