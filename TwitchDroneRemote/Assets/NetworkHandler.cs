using System;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;


public class NetworkHandler :  MonoBehaviour {
void Start() {
    
}


private void Update()
{
    if (Input.GetKeyDown(KeyCode.P))
    {
        print("cliked");
        StartCoroutine(Upload());
    }
}

IEnumerator Upload() {
    print("sent");
    WWWForm form = new WWWForm();
    form.AddField("State", "Hi its Dan");
 
    UnityWebRequest www = UnityWebRequest.Post("192.168.4.1", form);
    print(www.SendWebRequest().ToString());
    yield return www.SendWebRequest();
 
    if(www.isNetworkError || www.isHttpError) {
        Debug.Log(www.error);
    }
    else {
        Debug.Log("Form upload complete!");
    }
}
}