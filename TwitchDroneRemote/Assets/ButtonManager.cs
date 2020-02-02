using System.Collections;
using System.Collections.Generic;
using Kino;
using UnityEngine;
using UnityEngine.UI;

public class ButtonManager : MonoBehaviour
{
    // Start is called before the first frame update
    [SerializeField]private Button turnOn;
    [SerializeField]private Button pause;
    [SerializeField]private Button resume;
    [SerializeField] private float maxButtonSizeOnClick;
    [SerializeField] private float timeToStartBiggerButton;
    
    private bool onEnterTrigger = false;
    private bool onExitTrigger = false;
    
    private float initialTurnOnSize;
    private float initialPauseSize;
    private float initialResumeSize;

    private Camera mainCam;
    
    [SerializeField]private RectTransform curTurnOnSize;
    [SerializeField]private RectTransform curPauseSize;
    [SerializeField]private RectTransform curResumeSize;
    void Start()
    {
        mainCam = Camera.main;
        resume.enabled = false;
        pause.enabled = false;
        initialPauseSize = pause.GetComponent<RectTransform>().localScale.x;
        initialResumeSize = resume.GetComponent<RectTransform>().localScale.x;
        initialTurnOnSize = turnOn.GetComponent<RectTransform>().localScale.x;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnTurnOnEnter()
    {
        onExitTrigger = false;
        if (!onEnterTrigger && !onExitTrigger)
        {
            onEnterTrigger = true;
            StartCoroutine(StartBiger(turnOn,curTurnOnSize));
           
        }
    }
    
    public void OnTurnOnExit()
    {
        onEnterTrigger = false;
        if (!onEnterTrigger && !onExitTrigger)
        {
            onExitTrigger = true;
            StartCoroutine(StartSmaller(turnOn,initialTurnOnSize,curTurnOnSize));
           
        }
    }
    
    public void OnTurnOnClick()
    {
        onEnterTrigger = false;
        onExitTrigger = false;
        mainCam.GetComponent<AnalogGlitch>().enableAnalogeGlitch();
    }


    private IEnumerator StartBiger(Button target,RectTransform cur)
    {

        for (float i = cur.localScale.x; i < maxButtonSizeOnClick && onEnterTrigger; i+=0.1f)
        {
            cur.localScale = i*Vector3.one;
            yield return new WaitForSeconds(0.1f*timeToStartBiggerButton/maxButtonSizeOnClick);
        }
        onEnterTrigger = false;
        yield break;
    }
    private IEnumerator StartSmaller(Button target,float initial,RectTransform cur)
    {

        for (float i = cur.localScale.x;i>initial && onExitTrigger; i-=0.1f)
        {
            cur.localScale = i*Vector3.one;
            yield return new WaitForSeconds(0.1f*timeToStartBiggerButton/maxButtonSizeOnClick);
        }
       
        if(cur.localScale.x < 1 && onExitTrigger)
         cur.localScale = Vector3.one;
        onExitTrigger = false;
        yield break;
    }
}
