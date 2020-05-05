<?php

/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 05.05.2020
*/

header("Content-type:image/jpeg");

//First get the image 
$source_image = "image.jpg";

//And create image resources to process
$image_size = getimagesize($source_image);
$image = imagecreatetruecolor($image_size[0], $image_size[1]);
$image_resource = imagecreatefromjpeg($source_image);
imagecopy($image, $image_resource, 0, 0, 0, 0, $image_size[0], $image_size[1]);


//Extra we need to configure the watermark text 
//and font type, font size, color and text angle
$watermarktext = "Thecodeprogram";
$font = "COOPBL.TTF";
$fontsize = "25";
$color = imagecolorallocate($image, 255, 255, 255);
$textangle = 0;

//And location of the text on the image
$wm_x = $image_size[0] - 350 ;
$wm_y = $image_size[1] - 50;

//And then we write the text on the image.
imagettftext($image, $fontsize, $textangle, $wm_x, $wm_y, $color, $font, $watermarktext);

//Then show it on the page
imagejpeg($image);
imagedestroy($image);

?>