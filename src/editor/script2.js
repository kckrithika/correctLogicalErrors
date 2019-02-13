var testcases=1;
function addMore(element)
{
	var lastinput = document.getElementById("input"+testcases.toString());
	var lastoutput = document.getElementById("output"+testcases.toString());
	if((/\S/.test(lastinput.value))||(/\S/.test(lastoutput.value)))
	{
		var parent = element.parentNode;
		parent.removeChild(element);
		testcases = testcases+1;
	
		var br = document.createElement('br');
	
		var span = document.createElement('span');
		span.id = testcases.toString();
		span.innerHTML = "#"+testcases.toString()+" ";
	
		var text1 = document.createTextNode('Input: ');
		var input = document.createElement('textarea');
		input.id = "input"+testcases.toString();
	
		var text2 = document.createTextNode(' Output: ');
		var output = document.createElement('textarea');
		output.id = "output"+testcases.toString();
	
		parent.appendChild(br);
		parent.appendChild(span);
		parent.appendChild(text1);
		parent.appendChild(input);
		parent.appendChild(text2);
		parent.appendChild(output);
		parent.appendChild(element);
	}
	else
	{
		alert("Please enter i/o and then proceed");
	}
	return false;
}

function addquestion(element)
{
	var name = document.getElementById("name").innerHTML;
	var question = document.getElementById("question").innerHTML;
	var message = "name="+encodeURIComponent(name)+"&question="+encodeURIComponent(question);
	for(i=1; i<=testcases; i++)
	{
		var id = "input"+i.toString();
		message+="&"+id+"="+encodeURIComponent(document.getElementById(id).value);
		id = "output"+i.toString();
		message+="&"+id+"="+encodeURIComponent(document.getElementById(id).value);		
	}
	message+="&count="+testcases.toString();
	alert(message);
	var xmlhttp;
	if (window.XMLHttpRequest) 
	{
    	xmlhttp = new XMLHttpRequest();
    } 
    else 
   	{
	    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.open("POST", "addquestion.php", false);
	xmlhttp.onreadystatechange = function() 
	{
        if (xmlhttp.readyState == XMLHttpRequest.DONE ) 
		{
		    if(xmlhttp.status == 200)
			{
				alert(xmlhttp.responseText);
       		}
        }
	}
	
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xmlhttp.setRequestHeader("Content-length", message.length);
	xmlhttp.setRequestHeader("Connection", "close");
    xmlhttp.send(message);
    return false;
}
