<?
if($_GET[update]=="doit") {system("svn update"); exit; }
include "config.php";
if($_GET[cmd]=="PWM")$cmd="PWM";
elseif($_GET[cmd]=="SW")$cmd="SW";
elseif($_GET[cmd]=="beamer_on")$cmd="beamer_on";
elseif($_GET[cmd]=="text_the_borg")$cmd="text_the_borg";
elseif($_GET[cmd]=="treppenblink")$cmd="treppenblink";
elseif($_GET[cmd]=="canir_teufel")$cmd="canir_teufel";
elseif($_GET[cmd]=="canir_beamer")$cmd="canir_beamer";
elseif($_GET[cmd]=="moodbar")$cmd="moodbar";
elseif($_GET[cmd]=="moodbar_fade")$cmd="moodbar_fade";
elseif($_GET[cmd]=="save_pos")$cmd="save_pos";
elseif($_GET[cmd]=="save_bg")$cmd="save_bg";
elseif($_GET[cmd]=="blue_mode")$cmd="blue_mode";
elseif($_GET[cmd]=="toilet")$cmd="toilet";
elseif($_GET[cmd]=="dice")$cmd="dice";
elseif($_GET[cmd]=="coinflip")$cmd="coinflip";
elseif($_GET[cmd]=="w20")$cmd="w20";
elseif($_GET[cmd]=="twitter")$cmd="twitter";
else unset($_GET[cmd]);

if(in_array($_GET[id],$pwm_ids)) $id=$_GET[id];
elseif(in_array($_GET[id],$sw_ids)) $id=$_GET[id];
elseif(in_array($_GET[id],$toilet_ids)) $id=$_GET[id];
else unset($_GET[id]);

if($_COOKIE['toiletlamp']) $toiletlamp=$_COOKIE['toiletlamp'];
 else $toiletlamp=0;

if($cmd=="PWM")
{
	if(preg_match("/[!0-9]/",$_GET[value]) && $_GET[value]<=255 && $_GET[value]>=0) $value=dechex($_GET[value]);
	else unset($_GET[value]);
	if($id=="VORTRAG_PWM")
	{
		$_SESSION[$id]=hexdec($value);
		$_SESSION["TAFEL"]=hexdec($value);
		$_SESSION["BEAMER"]=hexdec($value);
		$_SESSION["SCHRANK"]=hexdec($value);
		$_SESSION["FLIPPER"]=hexdec($value);
		exec("powercommander.lapcontrol powercommander VIRT $id SET 0x$value");
		echo "powercommander.lapcontrol powercommander VIRT $id SET 0x$value";
	}
	else
	{
		$_SESSION[$id]=hexdec($value);
		exec("powercommander.lapcontrol powercommander $cmd $id SET 0x$value");
		echo "powercommander.lapcontrol powercommander $cmd $id SET 0x$value";
	}
}
elseif($cmd=="twitter")
{
#  echo "curl --basic --user Laboranten:\$LaborantenF00 --data status=\"".escapeshellcmd($_GET[text])."\" http://twitter.com/statuses/update.xml";

  exec("curl --basic --user Laboranten:\\\$LaborantenF00 --data status=\"".escapeshellcmd($_GET[text])."\" http://twitter.com/statuses/update.xml");
}
elseif($cmd=="SW")
{
	if($_GET[value]=="ON" || $_GET[value]=="OFF") $value=$_GET[value];
	if($id=="LAMP_VORTRAG_PWM")
	{
		if($value=="ON")
		{
			$_SESSION[$id]=1;
			$_SESSION["LAMP_TAFEL"]=1;
			$_SESSION["LAMP_BEAMER"]=1;
			$_SESSION["LAMP_SCHRANK"]=1;
			$_SESSION["LAMP_FLIPPER"]=1;
		}
		if($value=="OFF")
		{
			$_SESSION[$id]=0;
			$_SESSION["LAMP_TAFEL"]=0;
			$_SESSION["LAMP_BEAMER"]=0;
			$_SESSION["LAMP_SCHRANK"]=0;
			$_SESSION["LAMP_FLIPPER"]=0;
		}
		$id="VORTRAG";
		echo "powercommander.lapcontrol powercommander VIRT $id $value 0x00";
		exec("powercommander.lapcontrol powercommander VIRT $id $value 0x00");
	}
	else
	{
		if($value=="ON")$_SESSION[$id]=1;
		if($value=="OFF")$_SESSION[$id]=0;
		echo "powercommander.lapcontrol powercommander $cmd $id $value 0x00";
		exec("powercommander.lapcontrol powercommander $cmd $id $value 0x00");
	}
}
elseif($cmd=="beamer_on")
{
	exec("powercommander.lapcontrol powercommander SW PROJEKTOR ON 0x00");
	echo "powercommander.lapcontrol powercommander SW PROJEKTOR ON 0x00";
	$script .= "document.getElementById('beamer_button').disabled=true;\n";
	$_SESSION['beamer_on']=1;
}
elseif($cmd=="coinflip")
{
  $coin = 'number';
  if (rand(0,1) == '0') $coin = 'head';
  exec("lapcontrol -s rl borg scroll 0x24 '2<5|+30/#I fliped a coin and got ".$coin."'");
  exec("lapcontrol -s rl borg mode 0x24 1");
}
elseif($cmd=="dice")
{
  srand (time() );
  $dicevalue=rand(1,6);

  exec("lapcontrol -s rl borg scroll 0x24 '2<5|+30/#I rolled a dice and got ".$dicevalue."'");
  exec("lapcontrol -s rl borg mode 0x24 1");
}
elseif($cmd=="w20")
{
  srand (time() );
  $dicevalue=rand(1,20);
  if($dicevalue == 20) $dicevalue = 'FULL FAIL';
  if($dicevalue == 1) $dicevalue = 'Perfect';
  exec("lapcontrol -s rl borg scroll 0x24 '2<5|+30/#I rolled a W20 and got ".$dicevalue."'");
  exec("lapcontrol -s rl borg mode 0x24 1");
}
elseif($cmd=="toilet")
{
  if($id == 'TOILET_0') {
    if($_GET[value] == 'ON') {
      exec('touch /tmp/toilet_random');
    }
    else {
      exec('rm /tmp/toilet_random');
    }
  }
  if($id == 'TOILET_1') {
    if($_GET['value'] == 'ON') {
      $toiletlamp=$toiletlamp+1;
    } 
    else {
      $toiletlamp=$toiletlamp-1;
    }
  }
  if($id == 'TOILET_2') {
    if($_GET['value'] == 'ON') {
      $toiletlamp=$toiletlamp+2;
    } 
    else {
      $toiletlamp=$toiletlamp-2;
    }
  }
  if($id == 'TOILET_4') {
    if($_GET['value'] == 'ON') {
      $toiletlamp=$toiletlamp+4;
    } 
    else {
      $toiletlamp=$toiletlamp-4;
    }
  }
  if($id == 'TOILET_8') {
    if($_GET['value'] == 'ON') {
      $toiletlamp=$toiletlamp+8;
    } 
    else {
      $toiletlamp=$toiletlamp-8;
    }
  }
  if(($toiletlamp < 0) or ($toiletlamp >15)) $toiletlamp=0;
  setcookie("toiletlamp",$toiletlamp);
  echo "powercommander.lapcontrol packet 0x00:0x01 0x2a:0x01 0x00,".$toiletlamp;
  exec("powercommander.lapcontrol packet 0x00:0x01 0x2a:0x01 0x00,".$toiletlamp);
#	echo "powercommander.lapcontrol powercommander SW PROJEKTOR ON 0x00";
#	$script .= "document.getElementById('beamer_button').disabled=true;\n";
#	$_SESSION['beamer_on']=1;
}
elseif($cmd=="text_the_borg")
{
	echo "borg";
	exec("lapcontrol -s rl borg scroll 0x24 '2<5|+30/#".escapeshellcmd($_GET[text])."'");
	exec("lapcontrol -s rl borg mode 0x24 1");
}
elseif($cmd=="moodbar")
{
  $mood_green=0;
  $mood_blue=0;
  $mood_red=0;
  if($_GET[b] >=0 && $_GET[b] <=255) $mood_blue=255-$_GET[b];
  if($_GET[r] >=0 && $_GET[r] <=255) $mood_red=255-$_GET[r];
  if($_GET[g] >=0 && $_GET[g] <=255) $mood_green=255-$_GET[g];
  echo "powercommander.lapcontrol packet 0x00:0x00 0x31:0x17 0x03,0x00 && powercommander.lapcontrol packet 0x00:0x00 0x31:0x17 0x02,0x00,".$mood_blue.",".$mood_green.",".$mood_red; // stop mood
  exec("powercommander.lapcontrol packet 0x00:0x00 0x31:0x17 0x03,0x00 && powercommander.lapcontrol packet 0x00:0x00 0x31:0x17 0x02,0x00,".$mood_blue.",".$mood_green.",".$mood_red); // stop mood
}
elseif($cmd=="moodbar_fade")
{
  echo "powercommander.lapcontrol packet 0x00:0x00 0x31:0x17 0x03,0x01"; // enable mood
  exec("powercommander.lapcontrol packet 0x00:0x00 0x31:0x17 0x03,0x01"); // enable mood

}

elseif($cmd=="treppenblink")
{
  $real_tbm_value = "0x00";
  foreach ($treppenblink_modes as $tbm_key => $tbm_value)
    if($_GET[value]==$tbm_value || 
       $_GET[value]==$tbm_key ) $real_tbm_value=$tbm_value;

  echo "powercommander.lapcontrol treppenblink mode $real_tbm_value";
  exec("powercommander.lapcontrol treppenblink mode $real_tbm_value");
}
elseif($cmd=="canir_teufel")
{
  $real_canirteufel_value = "0x00";
  foreach ($canir_teufel_a as $cirt_key => $cirt_value)
    if($_GET['value']==$cirt_value || 
       $_GET['value']==$cirt_key ) $real_canirteufel_value=$cirt_value;
  foreach ($canir_teufel_a_channel as $cirt_key => $cirt_value)
    if($_GET['value']==$cirt_value || 
       $_GET['value']==$cirt_key ) $real_canirteufel_value=$cirt_value;

  echo "powercommander.lapcontrol canir teufel $real_canirteufel_value";
  exec("powercommander.lapcontrol canir teufel $real_canirteufel_value");
}
elseif($cmd=="canir_beamer")
{
  $real_canirbeamer_value = "0x00";
  foreach ($canir_beamer_a as $cirb_key => $cirb_value)
    if($_GET[value]==$cirb_value || 
       $_GET[value]==$cirb_key ) $real_canirbeamer_value=$cirb_value;
  foreach ($canir_beamer_a_channel as $cirb_key => $cirb_value)
    if($_GET[value]==$cirb_value || 
       $_GET[value]==$cirb_key ) $real_canirbeamer_value=$cirb_value;

  echo "powercommander.lapcontrol canir beamer $real_canirbeamer_value";
  exec("powercommander.lapcontrol canir beamer $real_canirbeamer_value");
}
elseif($cmd=="save_bg")
{
  if(in_array($_GET[bg], $background_images))
    {
      setcookie("bg",$_GET[bg],time()+60*60*24*30);
    }
}
elseif($cmd=="save_pos")
{
	setcookie($_GET[div]."x",$_GET[x]);
	setcookie($_GET[div]."y",$_GET[y]);
	echo "Element $_GET[div] $_GET[x] $_GET[y]";
}
elseif($cmd=="blue_mode")
{
	if($_GET[mode]=="on")
	{
		$_SESSION["LAMP_VORTRAG_PWM"]=1;
		$_SESSION["VORTRAG_PWM"]=255;
		$_SESSION["LAMP_TAFEL"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_TAFEL ON 0x00");
		$_SESSION["TAFEL"]="255";
		exec("powercommander.lapcontrol powercommander PWM TAFEL SET 0xff");
	
		$_SESSION["LAMP_BEAMER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_BEAMER ON 0x00");
		$_SESSION["BEAMER"]="255";
		exec("powercommander.lapcontrol powercommander PWM BEAMER SET 0xff");

		$_SESSION["LAMP_SCHRANK"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_SCHRANK ON 0x00");
		$_SESSION["SCHRANK"]="255";
		exec("powercommander.lapcontrol powercommander PWM SCHRANK SET 0xff");
		
		$_SESSION["LAMP_FLIPPER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_FLIPPER ON 0x00");
		$_SESSION["FLIPPER"]="255";
		exec("powercommander.lapcontrol powercommander PWM FLIPPER SET 0xff");
	}
	elseif($_GET[mode]=="off")
	{
		$_SESSION["LAMP_VORTRAG_PWM"]=0;
		$_SESSION["VORTRAG_PWM"]=0;
		$_SESSION["LAMP_TAFEL"]=0;
		exec("powercommander.lapcontrol powercommander SW LAMP_TAFEL OFF 0x00");
		$_SESSION["LAMP_BEAMER"]=0;
		exec("powercommander.lapcontrol powercommander SW LAMP_BEAMER OFF 0x00");
		$_SESSION["LAMP_SCHRANK"]=0;
		exec("powercommander.lapcontrol powercommander SW LAMP_SCHRANK OFF 0x00");
		$_SESSION["LAMP_FLIPPER"]=0;
		exec("powercommander.lapcontrol powercommander SW LAMP_FLIPPER OFF 0x00");
	}
	elseif($_GET[mode]=="video_conference")
	{
		$_SESSION["VORTRAG_PWM"]=0;
		$_SESSION["LAMP_TAFEL"]=0;
		exec("powercommander.lapcontrol powercommander SW LAMP_TAFEL OFF 0x00");

		$_SESSION["LAMP_BEAMER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_BEAMER ON 0x00");
		$_SESSION["BEAMER"]="0";
		exec("powercommander.lapcontrol powercommander PWM BEAMER SET 0x00");

		$_SESSION["LAMP_SCHRANK"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_SCHRANK ON 0x00");
		$_SESSION["SCHRANK"]="119";
		exec("powercommander.lapcontrol powercommander PWM SCHRANK SET 0x77");

		$_SESSION["LAMP_FLIPPER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_FLIPPER ON 0x00");
		$_SESSION["FLIPPER"]="255";
		exec("powercommander.lapcontrol powercommander PWM FLIPPER SET 0xff");
	}
	elseif($_GET[mode]=="speaker")
	{
		$_SESSION["VORTRAG_PWM"]=0;
		$_SESSION["LAMP_TAFEL"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_TAFEL ON 0x00");
		$_SESSION["TAFEL"]="255";
		exec("powercommander.lapcontrol powercommander PWM TAFEL SET 0xff");

		$_SESSION["LAMP_BEAMER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_BEAMER ON 0x00");
		$_SESSION["BEAMER"]="0";
		exec("powercommander.lapcontrol powercommander PWM BEAMER SET 0x00");

		$_SESSION["LAMP_SCHRANK"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_SCHRANK ON 0x00");
		$_SESSION["SCHRANK"]="0";
		exec("powercommander.lapcontrol powercommander PWM SCHRANK SET 0x00");

		$_SESSION["LAMP_FLIPPER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_FLIPPER ON 0x00");
		$_SESSION["FLIPPER"]="0";
		exec("powercommander.lapcontrol powercommander PWM FLIPPER SET 0x00");
	}
	elseif($_GET[mode]=="dimm")
	{
		$_SESSION["LAMP_VORTRAG_PWM"]=1;
		$_SESSION["VORTRAG_PWM"]=51;
		$_SESSION["LAMP_TAFEL"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_TAFEL ON 0x00");
		$_SESSION["TAFEL"]="51";
		exec("powercommander.lapcontrol powercommander PWM TAFEL SET 0x33");

		$_SESSION["LAMP_BEAMER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_BEAMER ON 0x00");
		$_SESSION["BEAMER"]="51";
		exec("powercommander.lapcontrol powercommander PWM BEAMER SET 0x33");

		$_SESSION["LAMP_SCHRANK"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_SCHRANK ON 0x00");
		$_SESSION["SCHRANK"]="51";
		exec("powercommander.lapcontrol powercommander PWM SCHRANK SET 0x33");

		$_SESSION["LAMP_FLIPPER"]=1;
		exec("powercommander.lapcontrol powercommander SW LAMP_FLIPPER ON 0x00");
		$_SESSION["FLIPPER"]="51";
		exec("powercommander.lapcontrol powercommander PWM FLIPPER SET 0x33");
	}
}

echo "<script>$script</script>";
?>
