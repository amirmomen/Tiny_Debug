# Tiny_Debug
A debug library written in **C/C++**. 
It is designed for **embedded systems**
  - Low memory usage
  - Very easy to use

  ## How to use

- **Print OK Message :**
```C
	DEBUG_OK("OK Message");
```

- **Print ERROR Message :**
```C
	DEBUG_ERROR("ERROR Message");
```

- **Print ALERT Message :**
```C
	DEBUG_ALERT("ALERT Message From %s", "Fire Station");
```

- **Print WARNING Message :**
```C
	DEBUG_WARNING("WARNING Message");
```

**Print Current Location in Code :**
```C
	DEBUG_TRACE();
```	

