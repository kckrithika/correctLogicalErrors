function enterAndTabHandler(e, textarea)
{
	var code = (e.keyCode ? e.keyCode : e.which);

	if(code == 13) 
	{ 
		getSuggestion();		
	}
	else if (code == 9) 
	{
		e.preventDefault();
    	var val = textarea.value,
        start = textarea.selectionStart,
        end = textarea.selectionEnd;
        textarea.value = val.substring(0, start) + '\t' + val.substring(end);
        textarea.selectionStart = textarea.selectionEnd = start + 1;
    }
    else
    {
    
    }
    var lines;
    if(textarea.value.match(/\n/g))
    {
    	lines=textarea.value.match(/\n/g).length+1;
    }
    else
    {
    	lines=1;
    }
	document.getElementById("LineNumber").innerHTML= "1";
	var numberoflines;
	for ( numberoflines = 2; numberoflines < lines+1; numberoflines++) 
	{ 
		document.getElementById("LineNumber").innerHTML= document.getElementById("LineNumber").innerHTML +"<br>"+ numberoflines;
	}
}

function compileAndRun()
{
	var code = document.getElementById("CodeSpace").value;
	var input = document.getElementById("input").value;
	var message = "code="+encodeURIComponent(code)+"&input="+encodeURIComponent(input);
	var xmlhttp;
	if (window.XMLHttpRequest) 
	{
    	xmlhttp = new XMLHttpRequest();
    } 
    else 
   	{
	    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.open("POST", "compileAndRun.php", false);
	xmlhttp.onreadystatechange = function() 
	{
        if (xmlhttp.readyState == XMLHttpRequest.DONE ) 
		{
		    if(xmlhttp.status == 200)
			{
				document.getElementById("output").innerHTML = xmlhttp.responseText.trim();
				return false;
       		}
        }
	}
	
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xmlhttp.setRequestHeader("Content-length", message.length);
	xmlhttp.setRequestHeader("Connection", "close");
    xmlhttp.send(message);
    return false;
}
function getSuggestion()
{
	var code = document.getElementById("CodeSpace").value;
	var message = "code="+encodeURIComponent(code);
	var xmlhttp;
	if (window.XMLHttpRequest) 
	{
    	xmlhttp = new XMLHttpRequest();
    } 
    else 
   	{
	    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.open("POST", "suggest.php", false);
	xmlhttp.onreadystatechange = function() 
	{
        if (xmlhttp.readyState == XMLHttpRequest.DONE ) 
		{
		    if(xmlhttp.status == 200)
			{
				//alert(xmlhttp.responseText);
				document.getElementById("suggestion").innerHTML = xmlhttp.responseText;
       		}
        }
	}
	
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xmlhttp.setRequestHeader("Content-length", message.length);
	xmlhttp.setRequestHeader("Connection", "close");
    xmlhttp.send(message);
    return false;
}
