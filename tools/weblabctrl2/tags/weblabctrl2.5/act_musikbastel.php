<?
require_once "system_conf.php";
require_once "container.php";

//var_dump($_GET);

if($_GET["doit"])
  {
    global $localstate;
    $tmpobj = new c_musikbastel();
    $command = $tmpobj->isvalidmode($_GET["function"]);
    $jsstr = "";

    foreach($sortedobjects[$tmpobj->getObjName()] as $myobj)
      {
	if( ( preg_match("/[!0-9]/",$_GET[$tmpobj->getObjName()."value"]) ) && 
	    ( $_GET[$myobj->getObjName()."value"]<=100 ) && 
	    ( $_GET[$myobj->getObjName()."value"]>=0 ) ) 
	  {
	    $value_dec=(int)$_GET[$myobj->getObjName()."value"];
	  }
      }

    
    switch ($command)
      {
      case "current":
	{
	}
      case "hacker":
	{
	  echo "I think it's a hacker";
	}
	break;
      case "play" :
	{
	  if($localstate["musik_bastel_status"]!="playing")
	    {
	      if($control=="enabled") exec("MPD_PORT=6602 mpc play") ;
	      $localstate["musik_bastel_status"]="playing";
	    }
	  foreach($sortedobjects[$tmpobj->getObjName()] as $myobj)
	    {
	      $jsstr .= $myobj->getid()."button_show_play_on();\n";
	      $jsstr .= $myobj->getid()."button_show_pause_off();\n";
	      $jsstr .= $myobj->getid()."button_show_stop_off();\n";
	    }
	}
	break;
      case "stop":
	{
	  if($localstate["musik_bastel_status"]!="stop")
	    {
	      if($control=="enabled") exec("MPD_PORT=6602 mpc stop") ;
	      $localstate["musik_bastel_status"]="stop";
	    }
	  foreach($sortedobjects[$tmpobj->getObjName()] as $myobj)
	    {
	      $jsstr .= $myobj->getid()."button_show_play_off();\n";
	      $jsstr .= $myobj->getid()."button_show_pause_off();\n";
	      $jsstr .= $myobj->getid()."button_show_stop_on();\n";
	    }
	}
	break;
      case "pause":
	{
	  if($localstate["musik_bastel_status"]!="paused")
	    {
	      if($control=="enabled") exec("MPD_PORT=6602 mpc pause") ;
	      $localstate["musik_bastel_status"]="paused";
	    }
	  foreach($sortedobjects[$tmpobj->getObjName()] as $myobj)
	    {
	      $jsstr .= $myobj->getid()."button_show_play_off();\n";
	      $jsstr .= $myobj->getid()."button_show_pause_on();\n";
	      $jsstr .= $myobj->getid()."button_show_stop_off();\n";
	    }
	}
	break;
      case "prev":
	{
	  if($control=="enabled") exec("MPD_PORT=6601 mpc prev") ;
	}
	break;
      case "next":
	{
	  if($control=="enabled") exec("MPD_PORT=6601 mpc next") ;
	}
	break;
      case "volume":
	{
	  if ( $localstate["musik_bastel_volume"]!=$value_dec)
	    {
	      if($control=="enabled") exec("MPD_PORT=6602 mpc volume ".$value_dec) ;
	      $localstate["musik_bastel_volume"]=$value_dec;
	    }

	}
	break;
      case "seek":
	{
	  if ( $localstate["musik_bastel_pos"]!=$value_dec)
	    {
	      if($control=="enabled") exec("MPD_PORT=6602 mpc seek ".$value_dec."\%") ;
	      $localstate["musik_bastel_pos"]=$value_dec;
	    }

	}
	break;
      default:
	{
	  echo "Idiot!";
	}
      }
    echo "<script>".$jsstr."</script>";
    file_put_contents($file, serialize( $localstate )); 
  }
