﻿String Content = "";
Content += "<HTML><HEAD><meta name='viewport' content='width=device-width, initial-scale=1'></meta><title>ESPeensy Control Panel</title>";
Content += "<STYLE>* {font-family:verdana;font-size:14px;border-radius:3px;Margin:3px;Padding:2px;}div {Border:1px solid grey;Margin-Bottom:7px;background-color:#E6E6E6;}";
Content += "h4 {Margin-Top:-2px;Margin-Left:-2px;Margin-Right:-2px;Padding:3px;background-color:#BDBDBD;}div>a{font-family:verdana;font-size:16px;Color:White;}";
Content += "div>a.Mark{background-color:#E6E6E6;color:black}Input,Select,Button{Border:1px solid lightgrey;Height:30px;Width:99%;Margin:0px;}";
Content += "Input:Hover,Select:Hover,Button:Hover,tr:hover{box-shadow: 0 0 0 1px #0080FF inset}table {Margin-Top:8px;width:99%;border-collapse:collapse;}";
Content += "th {text-align:left;height:20px;}td{Padding-right:6px}tr:nth-child(even) {background-color: #D8D8D8;}tr:first-child {box-shadow: 0 0 0 0px #0080FF inset}";
Content += "</STYLE></HEAD><BODY><DIV Style='background-color:#696969;Color:White;border-top: 2px solid blue;'><a Href='/'>Teensy Controls</a>";
Content += "<a Href='wifi'>Wifi Settings</a><a Href='fupload'>File Manager</a><a Href='updatefwm'>Firmware Manager</a></DIV><DIV><H4>Upload Files (Webfiles only, Multiple Files possible)</H4>";
Content += "<Table><TR><form method='POST' action='/fupload2' enctype='multipart/form-data'><TD><input type='file' name='Upload' multiple>";
Content += "</TD><TD><input type='submit' value='Upload'></TD></form></TR></Table></DIV><DIV><H4>Additional Information and Format</H4>";
Content += "<Table><TR><TD><i>TotalBytes: {Total}</i><BR><i>UsedBytes: {Used}</i></TD><TD><Button>Format</Button></TD></TR></Table></DIV>";
Content += "<DIV class='div1'><H4>Files on SPIFFS Storage</H4><table><TH>Filename</TH><TH>Filesize</TH><TR><TD><a href='Filename'>File1</a></TD><TD>10</TD>";
Content += "<TD width='15%'><a href='Filename'>Delete</a></TD></TR><TR><TD><a href='Filename'>File2</a></TD><TD>20</TD><TD width='10%'><a href='Filename'>Delete</a></TD>";
Content += "</TR><TR><TD><a href='Filename'>File3</a></TD><TD>20</TD><TD width='10%'><a href='Filename'>Delete</a></TD></TR><TR><TD><a href='Filename'>File4</a></TD><TD>20</TD>";
Content += "<TD width='10%'><a href='Filename'>Delete</a></TD></TR></table></DIV></BODY></HTML>";
